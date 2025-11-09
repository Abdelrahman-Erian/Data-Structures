#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T val){
        data = val;
        next = prev = nullptr;
    }
};

template< typename T>
class Deque
{
    int size;
    Node<T>* front;
    Node<T>* rear;
public:
    Deque()
    {
        size = 0;
        front = rear = nullptr;
    }

    void push_Front(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if(isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void push_Back(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if(isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop_Front()
    {
        if(isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if(front != nullptr) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        size--;
    }

    void pop_Back()
    {
        if(isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        Node<T>* temp = rear;
        rear = rear->prev;
        if(rear != nullptr) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        size--;
    }

    T getFront() const
    {
        if(isEmpty())
        {
            cout << "Deque is empty\n";
            return T();
        }
        return front->data;
    }
    T getBack() const
    {
        if(isEmpty())
        {
            cout << "Deque is empty\n";
            return T();
        }
        return rear->data;
    }
    bool isEmpty() const { return (front == nullptr); }
    int getSize() const { return size; }

    ~Deque() {
        while (front != nullptr) {
                Node<T>* temp = front;
                front = front->next;
                delete temp;
        }
    }

};
int main()
{
    Deque<int> dq;
    dq.push_Front(1);
    dq.push_Front(2);
    dq.push_Back(3);
    dq.push_Back(4);
    dq.push_Back(5);
    cout << "Front of Deque : " << dq.getFront() << endl;
    cout << "Back of Deque : " << dq.getBack() << endl;
    cout << "Size of Deque : " << dq.getSize() << endl;
    dq.pop_Front();
    cout << "After deleting front element, front : " << dq.getFront() << endl;
    dq.pop_Back();
    cout << "After deleting back element, back : " << dq.getBack() << endl;
}
