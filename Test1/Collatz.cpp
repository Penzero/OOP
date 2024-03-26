#include "Collatz.h"
#include <iostream>
#include <unordered_set>

Node::Node(int val) : info(val), next(nullptr) {
    prev[0] = nullptr;
    prev[1] = nullptr;
}

Collatz::Collatz() : head(nullptr) {}

static int collatz(int n) {
    return (n % 2 == 0) ? n / 2 : 3 * n + 1;
}

void Collatz::add(int val) {
    std::unordered_set<int> seen;
    std::cout << "Adding sequence for: " << val << std::endl;

    Node* lastNode = nullptr;
    bool cycleDetected = false;

    while (val != 1) {
        if (seen.find(val) != seen.end()) {
            std::cout << "Cycle detected at value: " << val << std::endl;
            cycleDetected = true;
            break;
        }
        seen.insert(val);

        if (valueMap.find(val) != valueMap.end()) {
            if (lastNode != nullptr) {
                lastNode->next = valueMap[val];
            }
            break;
        }

        int collatzVal = collatz(val);
        std::cout << val << " -> ";

        Node* newNode = new Node(collatzVal);
        if (head == nullptr) {
            head = newNode;
        } else if (lastNode != nullptr) {
            lastNode->next = newNode;
            newNode->prev[0] = lastNode;
        }

        lastNode = newNode;
        valueMap[collatzVal] = newNode;
        val = collatzVal;
    }

    if (!cycleDetected) {
        std::cout << "1 (End of sequence or linked to existing node)" << std::endl;
        if (val == 1 && valueMap.find(1) == valueMap.end()) {
            Node* oneNode = new Node(1);
            if (lastNode != nullptr) {
                lastNode->next = oneNode;
                oneNode->prev[0] = lastNode;
            } else {
                head = oneNode;
            }
            valueMap[1] = oneNode;
        }
    }
        
}

std::ostream& operator<<(std::ostream& os, const Collatz& list) {
    std::unordered_set<const Node*> visited;
    const Node* current = list.head;
    while (current != nullptr) {
        if (visited.find(current) == visited.end()) {
            os << current->info << " -> ";
            visited.insert(current);
            current = current->next;
        } else {
            os << "Found a cycle!";
            break;
        }
    }
    os << "NULL";
    return os;
}

Collatz::~Collatz() {
    std::unordered_set<Node*> deletedNodes;
    Node* current = head;
    while (current != nullptr) {
        if (deletedNodes.find(current) == deletedNodes.end()) {
            Node* toDelete = current;
            current = current->next;
            deletedNodes.insert(toDelete);
            delete toDelete;
        } else {
            break;
        }
    }
}