#include <iostream>
using namespace std;

const int MaxSize = 5000;

template <typename T>
class Stack
{
    T Items[MaxSize];
    int top, size;
public:
    Stack()
    {
        size = 0;
        top = -1;
    }
    void push(T element)
    {
        if(IsFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        Items[++top] = element;
        size++;
    }
    void pop()
    {
        if(IsEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
        size--;
    }
    T peek()
    {
        if(!IsEmpty()) return Items[top];
        return T();
    }
    bool IsEmpty()
    {
        return (top < 0);
    }
    bool IsFull()
    {
        return (top == MaxSize - 1);
    }
    int getSize()
    {
        return size;
    }

};
int main()
{
    Stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.peek() << "\n";
    cout << st.getSize() << "\n";
    while(!st.IsEmpty())
    {
        cout << st.peek() << " ";
        st.pop();
    }
}
