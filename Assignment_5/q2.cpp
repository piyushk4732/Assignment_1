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
 
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void count(int key){
        int count=0;
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                count++;

            }
            temp=temp->next;

            }
            cout<<count<<endl;
        }
    
    void deleteAllOccurence(int key)
    {

        while (head != NULL && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        Node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->next->data == key)
            {
                Node *temp = curr->next;
                curr->next = temp->next;


            }else{
                curr=curr->next;
            }

        }
    }
}

;

int main()
{
    List ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(1);
    int key = 1;
    ll.count(key);
    ll.deleteAllOccurence(key);

    ll.display();
    return 0;
}