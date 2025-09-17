#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() {
        return front == -1;
    }


    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) ;
    }


    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        
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
        } else if (front == MAX_SIZE - 1) {
            front = 0; 
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
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {

            for (int i = front; i < MAX_SIZE; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        

        cout << "Front at: " << front << ", Rear at: " << rear << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    cout << "=== Circular Queue Operations Menu ===" << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Check if Empty\n4. Check if Full\n";
        cout << "5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
                
            case 2:
                cq.dequeue();
                break;
                
            case 3:
                if (cq.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
                
            case 4:
                if (cq.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
                
            case 5:
                cq.display();
                break;
                
            case 6:
                cq.peek();
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