#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        // Deallocate memory for all nodes when the queue is destroyed
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued " << item << " to the queue" << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue element." << std::endl;
        } else {
            Node* temp = front;
            int removedItem = temp->data;
            front = front->next;
            delete temp;

            if (front == nullptr) {
                rear = nullptr; // If the queue is empty after dequeue
            }

            std::cout << "Dequeued " << removedItem << " from the queue" << std::endl;
        }
    }
};

int main() {
    // Example usage:
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    myQueue.dequeue();

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    return 0;
}