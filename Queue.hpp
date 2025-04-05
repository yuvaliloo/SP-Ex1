#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

//simple implementaion of Queue data structure
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
    Queue();             
    ~Queue();            

    void enqueue(int value);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
};

#endif 
