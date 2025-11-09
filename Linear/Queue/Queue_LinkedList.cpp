#include <iostream>

using namespace std;
template<typename T>
struct Node
{
    T data;
    Node* next;
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};

template< typename T>
class Queue
{
    int size;
    Node<T>* front;
    Node<T>* rear;
public:
    Queue()
    {
        size = 0;
        front = rear = nullptr;
    }
    void push(T val) // enqueue
    {
        Node<T>* newNode = new Node<T>(val);
        if(isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void pop() // dequeue
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* curr = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete curr;
        size--;
    }
    T getFront() const
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }
        return front->data;
    }
    bool isEmpty() const { return (front == nullptr); }
    int getSize() const { return size; }

    ~Queue() {
        while (front != nullptr) {
                Node<T>* temp = front;
                front = front->next;
                delete temp;
        }
    }

};
int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Front of queue : " << q.getFront() << endl;
    cout << "Size of queue : " << q.getSize() << endl;
    while(!q.isEmpty())
    {
        cout << q.getFront() << endl;
        q.pop();
    }

}
