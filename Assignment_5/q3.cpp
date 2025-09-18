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

    void middle()
    {
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<slow->data;

    }
};

int main()
{
    List ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);



    ll.middle();
    return 0;
}