#ifndef COLLATZ_H
#define COLLATZ_H


#include <iostream>
#include <unordered_map>

class Node{
    public:
        Node* prev[2];
        Node* next;
        int info;

        Node(int val);
};

class Collatz{
    private:
        std::unordered_map<int, Node*> valueMap;
    public:
        Node* head;

        Collatz();
        void add(int val);
        friend std::ostream& operator<<(std::ostream& os, const Collatz& list);
        ~Collatz();
};

#endif