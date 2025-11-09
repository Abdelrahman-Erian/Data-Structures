#include <iostream>

using namespace std;

const int MaxSize = 5000;

template <typename T>
class Queue
{
    int front, rear, size;
    T Items[MaxSize];
public:
    Queue()
    {
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return size == MaxSize;
    }

    T getFront()
    {
        if(!isEmpty()) return Items[front];
        return T();
    }

    int getSize()
    {
        return size;
    }

    void push(T element) // enqueue
    {
        if (isFull()) return;
		if (isEmpty()) front = 0;

		rear++;
		Items[rear] = element;
		++size;
    }

    void pop() // dequeue
    {
        if(isEmpty()) return;

        front++;
        size--;
        if (isEmpty()){
            front = rear = -1;
            size = 0;
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

    cout << q.getFront() << "\n";
    cout << q.getSize() << "\n";
    while(!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
}
