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
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
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
    void insertInBetween(int val, int pos)
    {
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)  
        {
            temp = temp->next;
        }
        
        if (temp == NULL) {
            cout << "Position out of bounds!\n";
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
    void deleteFromBegning()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void deleteFromEnd()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void deleteSpecificNode(int val)
    {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == val) {  
            deleteFromBegning();
            return;
        }
        
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        
        if (temp->next == NULL) {
            cout << "Value not found in the list!\n";
            return;
        }
        
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        
        if (toDelete == tail) {  
            tail = temp;
        }
        
        delete toDelete;
    }
    void search(int val)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout<< idx;
            }
            temp = temp->next;
            idx++;
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
};
int main()
{
    List ll;
    int choice, val, pos;
    do
    {
        cout << "\n1.Insertion at the beginning\n2.Insertion at the end.\n3.Insertion in between\n4.Deletion from the beginning\n5.Deletion from the end.\n6.Deletion of a specific node\n7.Search for a node and display its position from head\n8.Display all the node values.\n";
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the value you want to add at the begining: ";
            cin >> val;
            ll.insertAtBeginning(val);
            break;
        case 2:
            cout << "enter the value you want to add at the last: ";
            cin >> val;
            ll.insertAtEnd(val);
            break;
        case 3:
            cout << "enter the value which you want to add : ";
            cin >> val;
            cout << "enter the position where you want it: ";
            cin >> pos;
            ll.insertInBetween(val, pos);
            break;
        case 4:
            ll.deleteFromBegning();
            break;
        case 5:
            ll.deleteFromEnd();
            break;
        case 6:
            cout << "enter the node which you want to delete: ";
            cin >> val;
            ll.deleteSpecificNode(val);
            break;
        case 7:
            cout << "enter the node which you want to search: ";
            cin >> val;
            ll.search(val);
            break;
        case 8:
            ll.display();
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}