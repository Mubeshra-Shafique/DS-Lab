#include <iostream>

class Queue {
private:
    int capacity;
    int* queue;
    int front;
    int rear;

public:
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue element." << std::endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % capacity;
            }
            queue[rear] = item;
            std::cout << "Enqueued " << item << " to the queue" << std::endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue element." << std::endl;
        } else {
            int removedItem = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            std::cout << "Dequeued " << removedItem << " from the queue" << std::endl;
        }
    }
};

int main() {
    // Example usage:
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    myQueue.dequeue();

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    return 0;
}