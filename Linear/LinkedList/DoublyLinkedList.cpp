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

template <typename T>
class LinkedList {
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void insertAtFront(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if(head != nullptr) head->prev = newNode;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(const T& val) {
        Node<T>* newNode = new Node<T>(val);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            newNode->prev = curr;
            curr->next = newNode;
        }
        size++;
    }

    void insertPos(int pos, const T& val) {
        if (pos <= 0 || pos > size + 1) {
            cout << "Position must be between 1 and " << size + 1 << endl;
            return;
        }

        if (pos == 1) {
            insertAtFront(val);
            return;
        }

        Node<T>* curr = head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }

        Node<T>* newNode = new Node<T>(val);
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next = newNode;
        if(newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }
        size++;
    }

    void deleteAtFront()
    {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        if(head != nullptr) head->prev = nullptr;
        delete temp;
        size--;
    }

    void deleteAtEnd()
    {
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            deleteAtFront();
            return;
        }
        Node<T>* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->prev->next = nullptr;
        delete last;
        size--;
    }

    void deletePos(int pos)
    {
        if (pos <= 0 || pos > size) {
            cout << "Position must be between 1 and " << size << endl;
            return;
        }

        if (pos == 1) {
            deleteAtFront();
            return;
        }

        if(pos == size)
        {
            deleteAtEnd();
            return;
        }

        Node<T>* curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }

    int GetSize() const { return size; }

    bool IsEmpty() const { return size == 0; }

    bool search(const T& val) const
    {
        Node<T>* curr = head;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void reverseList() {
        Node<T>* curr = head;
        Node<T>* temp = nullptr;

        while(curr != nullptr)
        {
            swap(curr->prev, curr->next);
            temp = curr;
            curr = curr->prev;
        }

        if(temp != nullptr) head = temp;
    }

    void traverseList() const {
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr)
                cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    LinkedList<int> l;
    l.insertAtFront(1);
    l.insertAtFront(2);
    l.insertAtFront(3);
    l.insertAtEnd(4);
    l.insertPos(3, 5);
    l.insertPos(6, 6);
    cout << l.GetSize() << endl;
    l.traverseList();
    l.deleteAtFront();
    cout << l.GetSize() << endl;
    l.traverseList();
    l.deleteAtEnd();
    cout << l.GetSize() << endl;
    l.traverseList();
    l.deletePos(3);
    cout << l.GetSize() << endl;
    l.traverseList();
    l.reverseList();
    cout << l.GetSize() << endl;
    l.traverseList();
    /*cout << l.search(4) << endl;
    cout << l.search(3) << endl;*/
}
