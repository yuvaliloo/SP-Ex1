#include "Queue.hpp"
Queue::Queue() {
    front = rear = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};

    if (rear == nullptr) { 
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot dequeue!\n";
        return -1;
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == nullptr) { 
        rear = nullptr;
    }

    delete temp;
    size--;
    return value;
}

int Queue::peek() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot peek!\n";
        return -1;
    }
    return front->data;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}
