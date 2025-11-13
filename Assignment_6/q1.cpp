#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

struct CLLNode {
    int data;
    CLLNode* next;
};

class LinkedList {
private:
    DLLNode* dllHead;
    CLLNode* cllHead;

    void insertDLL(int data, int position, int afterValue = -1) {
        DLLNode* newNode = new DLLNode{data, nullptr, nullptr};
        
        if (dllHead == nullptr) { 
            dllHead = newNode;
            cout << "Inserted as first node\n";
            return;
        }
        
        if (position == 1) { 
            newNode->next = dllHead;
            dllHead->prev = newNode;
            dllHead = newNode;
            cout << "Inserted as first node\n";
        }
        else if (position == 2) { 
            DLLNode* temp = dllHead;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            cout << "Inserted as last node\n";
        }
        else if (position == 3) { 
            DLLNode* temp = dllHead;
            while (temp != nullptr && temp->data != afterValue)
                temp = temp->next;
            
            if (temp == nullptr) {
                cout << "Node not found!\n";
                delete newNode;
                return;
            }
            
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr)
                temp->next->prev = newNode;
            temp->next = newNode;
            cout << "Inserted after node " << afterValue << "\n";
        }
    }

    void deleteDLL(int value) {
        if (dllHead == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DLLNode* temp = dllHead;
   
        if (dllHead->data == value) {
            dllHead = dllHead->next;
            if (dllHead != nullptr)
                dllHead->prev = nullptr;
            delete temp;
            cout << "Node " << value << " deleted\n";
            return;
        }
        
        while (temp != nullptr && temp->data != value)
            temp = temp->next;
        
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        cout << "Node " << value << " deleted\n";
    }

    bool searchDLL(int value) {
        DLLNode* temp = dllHead;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void displayDLL() {
        if (dllHead == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DLLNode* temp = dllHead;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void insertCLL(int data, int position, int afterValue = -1) {
        CLLNode* newNode = new CLLNode{data, nullptr};
        
        if (cllHead == nullptr) {
            cllHead = newNode;
            newNode->next = cllHead;
            cout << "Inserted as first node\n";
            return;
        }
        
        if (position == 1) { 
            CLLNode* temp = cllHead;
            while (temp->next != cllHead)
                temp = temp->next;
            newNode->next = cllHead;
            temp->next = newNode;
            cllHead = newNode;
            cout << "Inserted as first node\n";
        }
        else if (position == 2) { 
            CLLNode* temp = cllHead;
            while (temp->next != cllHead)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = cllHead;
            cout << "Inserted as last node\n";
        }
        else if (position == 3) {
            CLLNode* temp = cllHead;
            do {
                if (temp->data == afterValue) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout << "Inserted after node " << afterValue << "\n";
                    return;
                }
                temp = temp->next;
            } while (temp != cllHead);
            cout << "Node not found!\n";
            delete newNode;
        }
    }

    void deleteCLL(int value) {
        if (cllHead == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        CLLNode *curr = cllHead, *prev = nullptr;

        if (cllHead->data == value) {
            if (cllHead->next == cllHead) { 
                delete cllHead;
                cllHead = nullptr;
            } else {
                CLLNode* temp = cllHead;
                while (temp->next != cllHead)
                    temp = temp->next;
                temp->next = cllHead->next;
                delete cllHead;
                cllHead = temp->next;
            }
            cout << "Node " << value << " deleted\n";
            return;
        }
        do {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                cout << "Node " << value << " deleted\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != cllHead);
        
        cout << "Node not found!\n";
    }

    bool searchCLL(int value) {
        if (cllHead == nullptr) return false;
        
        CLLNode* temp = cllHead;
        do {
            if (temp->data == value)
                return true;
            temp = temp->next;
        } while (temp != cllHead);
        return false;
    }

    void displayCLL() {
        if (cllHead == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        CLLNode* temp = cllHead;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != cllHead);
        cout << "\n";
    }

public:
    LinkedList() : dllHead(nullptr), cllHead(nullptr) {}
    
    void menu() {
        int choice, listType, data, position, value;
        
        while (true) {
            cout << "\n=== LINKED LIST OPERATIONS ===\n";
            cout << "1. Doubly Linked List\n";
            cout << "2. Circular Linked List\n";
            cout << "3. Exit\n";
            cout << "Choose list type: ";
            cin >> listType;
            
            if (listType == 3) break;
            if (listType != 1 && listType != 2) continue;
            
            while (true) {
                cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Back to Main\n";
                cout << "Enter choice: ";
                cin >> choice;
                
                switch (choice) {
                    case 1: // Insert
                        cout << "Enter data: ";
                        cin >> data;
                        cout << "1. First node\n2. Last node\n3. After specific node\n";
                        cout << "Choose position: ";
                        cin >> position;
                        
                        if (position == 3) {
                            cout << "Enter node value to insert after: ";
                            cin >> value;
                        }
                        
                        if (listType == 1) insertDLL(data, position, value);
                        else insertCLL(data, position, value);
                        break;
                        
                    case 2: // Delete
                        cout << "Enter node value to delete: ";
                        cin >> value;
                        if (listType == 1) deleteDLL(value);
                        else deleteCLL(value);
                        break;
                        
                    case 3: // Search
                        cout << "Enter node value to search: ";
                        cin >> value;
                        if (listType == 1) 
                            cout << (searchDLL(value) ? "Found!\n" : "Not found!\n");
                        else
                            cout << (searchCLL(value) ? "Found!\n" : "Not found!\n");
                        break;
                        
                    case 4: 
                        if (listType == 1) displayDLL();
                        else displayCLL();
                        break;
                        
                    case 5: 
                        break;
                        
                    default:
                        cout << "Invalid choice!\n";
                }
                if (choice == 5) break;
            }
        }
    }
};

int main() {
    LinkedList list;
    list.menu();
    return 0;
}