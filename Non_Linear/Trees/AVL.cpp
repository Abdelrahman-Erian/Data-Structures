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
class AVL
{
    Node<T>* root;

    int height(Node<T>* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int getBalanceFactor(Node<T>* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node<T>* RightRotate(Node<T>* rootNode) { // LL
        Node<T>* newRoot = rootNode->left;
        Node<T>* rst = newRoot->right;

        newRoot->right = rootNode;
        rootNode->left = rst;

        return newRoot;
    }

    Node<T>* LeftRotate(Node<T>* rootNode) { // RR
        Node<T>* newRoot = rootNode->right;
        Node<T>* lst = newRoot->left;

        newRoot->left = rootNode;
        rootNode->right = lst;

        return newRoot;
    }

    Node<T>* insert(Node<T>* node, T val) {
        if (node == nullptr)
            return new Node<T>(val);

        if (val == node->data)
            return node;
        else if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        int bf = getBalanceFactor(node);

        // Left Left Case
        if (bf > 1 && val < node->left->data)
            return RightRotate(node);

        // Right Right Case
        if (bf < -1 && val > node->right->data)
            return LeftRotate(node);

        // Left Right Case
        if (bf > 1 && val > node->left->data) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        // Right Left Case
        if (bf < -1 && val < node->right->data) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

    Node<T>* FindMinNode(Node<T>* node) {
        while (node != nullptr && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node<T>* FindMaxNode(Node<T>* node) {
        while (node != nullptr && node->right != nullptr)
            node = node->right;
        return node;
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

        int bf = getBalanceFactor(node);

        // Left Left Case
        if (bf > 1 && getBalanceFactor(node->left) >= 0)
            return RightRotate(node);

        // Right Right Case
        if (bf < -1 && getBalanceFactor(node->right) <= 0)
            return LeftRotate(node);

        // Left Right Case
        if (bf > 1 && getBalanceFactor(node->left) < 0) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        // Right Left Case
        if (bf < -1 && getBalanceFactor(node->right) > 0) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

    void printLevelbyLevel(Node<T>* node) { // Breadth First Search (BFS)
        if (node == nullptr) return;

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

    void clear(Node<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    AVL() : root(nullptr) {}

    ~AVL() {
        clear(root);
    }

    void insert(const T& val) {
        root = insert(root, val);
    }

    void deletnode(T val) { root = deletnode(root, val); }

    void printLevelbyLevel() { printLevelbyLevel(root); }

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
};

int main()
{
    AVL<int> avl;
    avl.insert(8);
    avl.insert(5);
    avl.insert(10);
    avl.insert(2);
    avl.insert(7);

    avl.deletnode(10);
    avl.printLevelbyLevel();
}
