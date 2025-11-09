#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T* Items;
    int front, rear, size, capacity;

    void init(int cap = 2) {
        capacity = cap;
        Items = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void resize() {
        int newCapacity = capacity * 2;
        T* temp = new T[newCapacity];

        for (int i = 0; i < size; i++) {
            temp[i] = Items[front + i];
        }

        delete[] Items;
        Items = temp;
        front = 0;
        rear = size - 1;
        capacity = newCapacity;
    }

public:
    Queue() { init(); }
    ~Queue() { delete[] Items; }

    void push(T element) {
        if (isFull()) resize(); // resize
        rear++;
        Items[rear] = element;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
        size--;
        if (size == 0) { // reset indices
            front = 0;
            rear = -1;
        }
    }

    T getFront() const {
        if (!isEmpty()) return Items[front];
        return T();
    }

    bool isEmpty() const { return size == 0; }

    bool isFull() const { return rear + 1 == capacity; }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};

int main() {
    Queue<int> q;

    for (int i = 1; i <= 10; i++) q.push(i);

    cout << "Front: " << q.getFront() << "\n";
    cout << "Size: " << q.getSize() << "\n";
    cout << "Capacity: " << q.getCapacity() << "\n";

    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.pop();
    }
}
