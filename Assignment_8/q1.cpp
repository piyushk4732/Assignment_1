#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";  
    preOrder(root->left);       
    preOrder(root->right);     
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    
    inOrder(root->left);        
    cout << root->data << " ";  
    inOrder(root->right);    
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    
    postOrder(root->left);      
    postOrder(root->right);     
    cout << root->data << " ";  
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;
    
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;
    
    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}