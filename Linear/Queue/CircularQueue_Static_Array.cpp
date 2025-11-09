#include <iostream>
using namespace std;

const int MaxSize = 5000;

template <typename T>
class CircularQueue {
    int front, rear, size;
    T Items[MaxSize];

public:
    CircularQueue() {
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MaxSize;
    }

    T getFront() {
        if (!isEmpty()) return Items[front];
        return T();
    }

    int getSize() {
        return size;
    }

    void push(T element) { // enqueue
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MaxSize;
        }
        Items[rear] = element;
        size++;
    }

    void pop() { // dequeue
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MaxSize;
        }
        size--;
    }
};

int main() {
    CircularQueue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Front: " << q.getFront() << "\n";
    cout << "Size: " << q.getSize() << "\n";

    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.pop();
    }
}
