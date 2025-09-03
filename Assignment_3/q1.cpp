#include <iostream>
using namespace std;

#define MAX 5
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
        case 2: s.pop(); break;
        case 3: s.peek(); break;
        case 4: s.display(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}