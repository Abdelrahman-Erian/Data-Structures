#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T* Items;
    int top, size, capacity;
private:
    void init(const int&cap = 1){ // initialize of stack
      top = -1;
      size = 0;
      capacity = cap;
      Items = new T[cap];
   }
   void Resize(){
      T *tempItems = new T[capacity] ;
      for(int i = 0 ; i < capacity ; i++)
         tempItems[i] = Items[i] ;


      Items = new T[2 * capacity] ;

      for(int i = 0 ; i < capacity ; i++)
         Items[i] = tempItems[i] ;

      delete [] tempItems;

      capacity *= 2 ;
   }
public:
    Stack(){ init(); }
    ~Stack()
    {
        delete[] Items;
    }
    void push(T element)
    {
      if(size == capacity) Resize() ; // resize
      size++;
      Items[++top] = element;
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
    int getSize()
    {
        return size;
    }
    int getcCapacity()
    {
        return capacity;
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
