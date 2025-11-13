#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

bool isPalindrome(Node* head) {
    if (head == NULL) return true;
    
    Node* start = head;
    Node* end = head;
    while (end->next != NULL) {
        end = end->next;
    }
    while (start != end) {
        if (start->data != end->data) {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    Node* head = new Node('L');
    head->next = new Node('E');
    head->next->prev = head;
    head->next->next = new Node('V');
    head->next->next->prev = head->next;
    head->next->next->next = new Node('E');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('L');
    head->next->next->next->next->prev = head->next->next->next;
    cout << (isPalindrome(head) ? "True" : "False");
    return 0;
}