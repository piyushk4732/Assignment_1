#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
private:
    queue<int> q1, q2;
    
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    void pop() {
        if (!isEmpty()) {
            q1.pop();
        }
    }
    
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return q1.front();
    }
    
    bool isEmpty() {
        return q1.empty();
    }
    
    int size() {
        return q1.size();
    }
    
    void display() {
        queue<int> temp = q1;
        cout << "Two Queues Stack: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

class StackOneQueue {
private:
    queue<int> q;
    
public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop() {
        if (!isEmpty()) {
            q.pop();
        }
    }
    
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    int size() {
        return q.size();
    }
    
    void display() {
        queue<int> temp = q;
        cout << "One Queue Stack: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {

    cout << "\n1. Using Two Queues:" << endl;
    StackTwoQueues stackTwo;
    
    stackTwo.push(10);
    stackTwo.push(20);
    stackTwo.push(30);
    stackTwo.display();
    cout << "Top: " << stackTwo.top() << endl;
    
    stackTwo.pop();
    stackTwo.display();
    cout << "Top after pop: " << stackTwo.top() << endl;
    
    stackTwo.push(40);
    stackTwo.display();

    cout << "\n2. Using One Queue:" << endl;
    StackOneQueue stackOne;
    
    stackOne.push(10);
    stackOne.push(20);
    stackOne.push(30);
    stackOne.display();
    cout << "Top: " << stackOne.top() << endl;
    
    stackOne.pop();
    stackOne.display();
    cout << "Top after pop: " << stackOne.top() << endl;
    
    stackOne.push(40);
    stackOne.display();


    return 0;
}