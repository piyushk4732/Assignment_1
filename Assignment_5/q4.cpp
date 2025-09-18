#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void printlist()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    List ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.reverse();
    ll.printlist();
    return 0;
}