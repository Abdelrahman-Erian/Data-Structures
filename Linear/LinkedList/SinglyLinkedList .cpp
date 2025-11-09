#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void insertAtFront(const T& val) {
        Node<T>* newNode = new Node<T>(val);
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
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtFront()
    {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
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
        Node<T>* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        delete secondLast->next;
        secondLast->next = nullptr;
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

        Node<T>* curr = head;
        Node<T>* prev = nullptr;
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
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

        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;
        while (head != nullptr) {

            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
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
