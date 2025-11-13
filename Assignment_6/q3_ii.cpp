#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int findSize(Node* head) {
    if (head == NULL) {
        return 0;
    }
    
    int count = 0;
    Node* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    
    return count;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    cout << findSize(head);
    return 0;
}