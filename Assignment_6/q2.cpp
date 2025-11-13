#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(NULL) {}
    
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    void displayWithHeadRepeat() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Output: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
    
    void createSampleList() {
        insert(20);
        insert(100);
        insert(40);
        insert(80);
        insert(60);
    }
};

int main() {
    CircularLinkedList list;
    list.createSampleList();
    list.displayWithHeadRepeat();
    return 0;
} 