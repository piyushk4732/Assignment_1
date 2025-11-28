#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    bool isBSTUtil(Node* node, int min, int max) {

        if (node == nullptr) {
            return true;
        }
 
        if (node->data <= min || node->data >= max) {
            return false;
        }
 
        return isBSTUtil(node->left, min, node->data) && 
               isBSTUtil(node->right, node->data, max);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
 
    void setRoot(Node* node) {
        root = node;
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    bool isBSTInorder() {
        static Node* prev = nullptr;
        return isBSTInorderUtil(root, prev);
    }
    
    bool isBSTInorderUtil(Node* node, Node* &prev) {
 
        if (node == nullptr) {
            return true;
        }

        if (!isBSTInorderUtil(node->left, prev)) {
            return false;
        }

        if (prev != nullptr && node->data <= prev->data) {
            return false;
        }
        prev = node;
   
        return isBSTInorderUtil(node->right, prev);
    }

    void display() {
        cout << "In-order traversal: ";
        inorder(root);
        cout << endl;
    }
};

void testBST() {
    BinaryTree tree;

    Node* root1 = new Node(50);
    root1->left = new Node(30);
    root1->right = new Node(70);
    root1->left->left = new Node(20);
    root1->left->right = new Node(40);
    root1->right->left = new Node(60);
    root1->right->right = new Node(80);
    tree.setRoot(root1);
    tree.display();
    cout << "Is BST? " << (tree.isBST() ? "Yes" : "No") << endl;


}
int main() {
    testBST();
    return 0;
}