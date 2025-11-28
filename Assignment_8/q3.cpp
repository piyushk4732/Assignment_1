#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }
        
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {

            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->data = temp->data;
            

            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    int minDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr) {
            return minDepth(node->right) + 1;
        }

        if (node->right == nullptr) {
            return minDepth(node->left) + 1;
        }

        return min(minDepth(node->left), minDepth(node->right)) + 1;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteElement(int key) {
        root = deleteNode(root, key);
    }

    int getMaxDepth() {
        return maxDepth(root);
    }

    int getMinDepth() {
        return minDepth(root);
    }

    void display() {
        cout << "In-order traversal: ";
        inorder(root);
        cout << endl;
    }

    bool search(int key) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            } else if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BST bst;

    cout << "\n1. Inserting elements..." << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(25);
    
    bst.display();

    cout << "\n2. Depth of BST:" << endl;
    cout << "Maximum depth: " << bst.getMaxDepth() << endl;
    cout << "Minimum depth: " << bst.getMinDepth() << endl;

    cout << "\n3. Deleting elements..." << endl;

    cout << "Deleting 25 (leaf node)..." << endl;
    bst.deleteElement(25);
    bst.display();
    cout << "Search for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 20 (node with one child)..." << endl;
    bst.deleteElement(20);
    bst.display();
  
    cout << "\nDeleting 30 (node with two children)..." << endl;
    bst.deleteElement(30);
    bst.display();

    cout << "\n4. Final depth of BST:" << endl;
    cout << "Maximum depth: " << bst.getMaxDepth() << endl;
    cout << "Minimum depth: " << bst.getMinDepth() << endl;
    return 0;
}