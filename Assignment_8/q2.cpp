#include <iostream>
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

    Node* searchRecursive(Node* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }
        if (key < node->data) {
            return searchRecursive(node->left, key);
        }
        return searchRecursive(node->right, key);
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

    bool searchRecursive(int key) {
        return searchRecursive(root, key) != nullptr;
    }

    bool searchNonRecursive(int key) {
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

    int findMax() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    int findMin() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    int inorderSuccessor(int key) {
        Node* current = root;
        Node* successor = nullptr;
        
        while (current != nullptr) {
            if (key < current->data) {
                successor = current;
                current = current->left;
            } else if (key > current->data) {
                current = current->right;
            } else {
                if (current->right != nullptr) {

                    Node* temp = current->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    return temp->data;
                }
                break;
            }
        }
        return successor != nullptr ? successor->data : -1;
    }

    int inorderPredecessor(int key) {
        Node* current = root;
        Node* predecessor = nullptr;
        
        while (current != nullptr) {
            if (key > current->data) {
                predecessor = current;
                current = current->right;
            } else if (key < current->data) {
                current = current->left;
            } else {
                if (current->left != nullptr) {

                    Node* temp = current->left;
                    while (temp->right != nullptr) {
                        temp = temp->right;
                    }
                    return temp->data;
                }
                break;
            }
        }
        return predecessor != nullptr ? predecessor->data : -1;
    }

    void displayInorder() {
        cout << "In-order traversal: ";
        inorder(root);
        cout << endl;
    }
};
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.displayInorder();
    cout << "\nSearch operations:" << endl;
    cout << "Search 40 (Recursive): " << (bst.searchRecursive(40) ? "Found" : "Not Found") << endl;
    cout << "Search 40 (Non-Recursive): " << (bst.searchNonRecursive(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100 (Recursive): " << (bst.searchRecursive(100) ? "Found" : "Not Found") << endl;
    cout << "\nMax and Min elements:" << endl;
    cout << "Maximum element: " << bst.findMax() << endl;
    cout << "Minimum element: " << bst.findMin() << endl;
    cout << "\nIn-order Successor and Predecessor:" << endl;
    cout << "In-order successor of 40: " << bst.inorderSuccessor(40) << endl;
    cout << "In-order predecessor of 40: " << bst.inorderPredecessor(40) << endl;
    cout << "In-order successor of 70: " << bst.inorderSuccessor(70) << endl;
    cout << "In-order predecessor of 20: " << bst.inorderPredecessor(20) << endl;
    
    return 0;
}