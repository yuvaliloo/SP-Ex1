#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue();             // Constructor
    ~Queue();            // Destructor

    void enqueue(int value);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
};

#endif // QUEUE_HPP
