#include "Queue.hpp"
// Constructor: Initialize queue
Queue::Queue() {
    front = rear = nullptr;
    size = 0;
}

// Destructor: Free all nodes
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Enqueue (add element at the rear)
void Queue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};

    if (rear == nullptr) { // If queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

// Dequeue (remove element from the front)
int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot dequeue!\n";
        return -1;
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == nullptr) { // If queue becomes empty
        rear = nullptr;
    }

    delete temp;
    size--;
    return value;
}

// Peek (get the front element without removing it)
int Queue::peek() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot peek!\n";
        return -1;
    }
    return front->data;
}

// Check if the queue is empty
bool Queue::isEmpty() const {
    return front == nullptr;
}
