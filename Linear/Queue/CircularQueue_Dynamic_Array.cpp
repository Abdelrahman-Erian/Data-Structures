#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
    T* Items;
    int front, rear, size, capacity;

    void init(int cap = 2) {
        capacity = cap;
        Items = new T[capacity];
        front = rear = -1;
        size = 0;
    }

    void resize() {
        int newCapacity = capacity * 2;
        T* temp = new T[newCapacity];

        for (int i = 0; i < size; i++) {
            temp[i] = Items[(front + i) % capacity];
        }

        delete[] Items;
        Items = temp;
        front = 0;
        rear = size - 1;
        capacity = newCapacity;
    }

public:
    CircularQueue() { init(); }
    ~CircularQueue() { delete[] Items; }

    void push(T element) {
        if (isFull()) resize(); // resize

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        Items[rear] = element;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    T getFront() const {
        if (!isEmpty()) return Items[front];
        return T();
    }

    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};

int main() {
    CircularQueue<int> q;

    for (int i = 1; i <= 10; i++) q.push(i);

    cout << "Front: " << q.getFront() << "\n";
    cout << "Size: " << q.getSize() << "\n";
    cout << "Capacity: " << q.getCapacity() << "\n";

    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.pop();
    }
}
