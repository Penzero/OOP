#include "Collatz.h"
#include <iostream>
#include <cassert>

void testNode() {
    // Creating nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Manually linking nodes
    // Link first and second
    first->next = second;
    second->prev[0] = first;

    // Link second and third
    second->next = third;
    third->prev[0] = second;
    // Optionally, set third->previous[1] to first to test the dual previous linkage
    third->prev[1] = first;

    // Assertions to verify our structure
    assert(first->next == second); // First's next should be second
    assert(second->prev[0] == first); // Second's previous[0] should be first
    assert(second->next == third); // Second's next should be third
    assert(third->prev[0] == second); // Third's previous[0] should be second
    assert(third->prev[1] == first); // Third's previous[1] should be first, testing dual linkage

    std::cout << "All tests passed successfully." << std::endl;

    // Cleanup
    delete first;
    delete second;
    delete third;
}

int main(){
    testNode();
}