#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node() : data(), left(nullptr), right(nullptr) {}
    Node(const T& key) : data(key), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST
{
    Node<T>* root;

    Node<T>* insert(Node<T>* node, T val) {
        if (node == nullptr)
            return new Node<T>(val);

        if (val == node->data)
            return node;
        else if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void inorder(Node<T>* node) {
        // left -> root -> right
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node<T>* node) {
        // root -> left -> right
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node<T>* node) {
        // left -> right -> root
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void printLevel(Node<T>* node, int level) {
        if (node == nullptr)
            return;

        if (level == 0)
            cout << node->data << " ";
        else {
            printLevel(node->left, level - 1);
            printLevel(node->right, level - 1);
        }
    }

    void printLevelbyLevel(Node<T>* node) { // Breadth First Search (BFS)
        if (node == nullptr)
            return;

        queue<Node<T>*> q;
        q.push(node);
        while (!q.empty()) {
            int size_level = q.size();
            while (size_level--) {
                Node<T>* cur_node = q.front();
                q.pop();
                cout << cur_node->data << " ";
                if (cur_node->left != nullptr) q.push(cur_node->left);
                if (cur_node->right != nullptr) q.push(cur_node->right);
            }
            cout << "\n";
        }
    }

    int height(Node<T>* node) {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int CountNodes(Node<T>* node) {
        if (node == nullptr)
            return 0;

        int cnt = 0;
        queue<Node<T>*> q;
        q.push(node);
        while (!q.empty()) {
            Node<T>* cur = q.front();
            q.pop();
            cnt++;
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        return cnt;
    }

    int CountLeaf(Node<T>* node) {
        if (node == nullptr)
            return 0;

        int cnt = 0;
        queue<Node<T>*> q;
        q.push(node);
        while (!q.empty()) {
            Node<T>* cur = q.front();
            q.pop();
            if (cur->left == nullptr && cur->right == nullptr)
                cnt++;
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        return cnt;
    }

    Node<T>* FindMaxNode(Node<T>* node) {
        while (node != nullptr && node->right != nullptr)
            node = node->right;
        return node;
    }

    Node<T>* FindMinNode(Node<T>* node) {
        while (node != nullptr && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node<T>* Search(Node<T>* node, T val) {
        if (node == nullptr)
            return nullptr;
        if (node->data == val)
            return node;
        if (val < node->data)
            return Search(node->left, val);
        return Search(node->right, val);
    }

    Node<T>* deletnode(Node<T>* node, T val) {
        if (node == nullptr)
            return node;

        if (val < node->data)
            node->left = deletnode(node->left, val);
        else if (val > node->data)
            node->right = deletnode(node->right, val);
        else {
            // Leaf
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // One child
            else if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }
            // Two children
            else {
                Node<T>* cur = FindMinNode(node->right);
                node->data = cur->data;
                node->right = deletnode(node->right, cur->data);
            }
        }
        return node;
    }

    void clear(Node<T>* node) {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const T& val) {
        root = insert(root, val);
    }

    void inorder() { inorder(root); }
    void preorder() { preorder(root); }
    void postorder() { postorder(root); }

    void printlevel(int level) { printLevel(root, level); }
    void printLevelbyLevel() { printLevelbyLevel(root); }

    void deletnode(T val) { root = deletnode(root, val); }

    bool search(T val) {
        return (Search(root, val) != nullptr);
    }

    T FindMin() {
        Node<T>* mn = FindMinNode(root);
        if (mn == nullptr) throw runtime_error("Tree is empty");
        return mn->data;
    }

    T FindMax() {
        Node<T>* mx = FindMaxNode(root);
        if (mx == nullptr) throw runtime_error("Tree is empty");
        return mx->data;
    }

    bool isEmpty() { return root == nullptr; }
    int Height() { return height(root); }
    int CountLeaf() { return CountLeaf(root); }
    int CountNodes() { return CountNodes(root); }
};

int main()
{
    BST<int> b;
    b.insert(10);
    b.insert(5);
    b.insert(8);
    b.insert(2);
    b.insert(12);
    b.insert(11);
    b.insert(20);
    b.insert(15);
    b.insert(18);
    b.insert(14);
    b.insert(25);
    b.insert(30);
    cout << "Preorder : \n";
    b.preorder();
    cout << "\n";
    cout << "----------------------\n";
    cout << "Postorder : \n";
    b.postorder();
    cout << "\n";
    cout << "----------------------\n";
    cout << "Inorder : \n";
    b.inorder();
    cout << "\n";
    cout << "----------------------\n";
    cout << "printLevelbyLvel( BFS ) : \n";
    b.printLevelbyLevel();
    cout << "----------------------\n";
    if (!b.isEmpty())
    {
        cout << "Min Value : " << b.FindMin() << "\n";
        cout << "Max Value : " << b.FindMax() << "\n";
    }
    else
    {
        cout << "Error: Tree is empty!" << "\n";
    }
    cout << "Hight : " << b.Height() << "\n";
    cout << "Count Nodes : " << b.CountNodes() << "\n";
    cout << "Count Leaves : " << b.CountLeaf() << "\n";
    cout << "IsEmpty :" << b.isEmpty() << "\n";
    cout << "Search Node with value {40} : " << ( b.search(40) ? "Found" : "NotFound" ) << "\n";
}
