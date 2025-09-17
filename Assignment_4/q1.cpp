#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() {
        return front == -1;
    }


    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

 
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " enqueued successfully." << endl;
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        int removedValue = arr[front];
        cout << removedValue << " dequeued successfully." << endl;
        

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }


    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No element to peek." << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "=== Simple Queue Operations Menu ===" << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Check if Empty\n4. Check if Full\n";
        cout << "5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                q.dequeue();
                break;
                
            case 3:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
                
            case 4:
                if (q.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
                
            case 5:
                q.display();
                break;
                
            case 6:
                q.peek();
                break;
                
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}