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
class Stack
{
    int size;
    Node<T>* top;
public:
    Stack()
    {
        size = 0;
        top = nullptr;
    }
    void push(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
        size++;
    }
    T peek() const
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return T();
        }
        return top->data;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* curr = top;
        top = top->next;
        delete curr;
        size--;
    }
    bool isEmpty() const { return (top == nullptr); }
    int getSize() const { return size; }

    ~Stack() {
        while (top != nullptr) {
                Node<T>* temp = top;
                top = top->next;
                delete temp;
        }
    }

};
int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Top of stack : " << st.peek() << endl;
    cout << "Size of stack : " << st.getSize() << endl;
    while(!st.isEmpty())
    {
        cout << st.peek() << endl;
        st.pop();
    }

}
