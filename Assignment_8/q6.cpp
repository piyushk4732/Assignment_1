#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();

        if (left < n && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        if (right < n && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:

    MaxPriorityQueue() {}
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return INT_MIN;
        }
        return heap[0];
    }

    int extractMax() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return INT_MIN;
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!isEmpty()) {
            heapifyDown(0);
        }
        
        return max;
    }

    void remove(int i) {
        if (i < 0 || i >= heap.size()) {
            cout << "Invalid index!" << endl;
            return;
        }
        heap[i] = INT_MAX; 
        heapifyUp(i);    
        extractMax();      
    }

    void changePriority(int i, int newValue) {
        if (i < 0 || i >= heap.size()) {
            cout << "Invalid index!" << endl;
            return;
        }

        int oldValue = heap[i];
        heap[i] = newValue;

        if (newValue > oldValue) {
            heapifyUp(i);
        } else {
            heapifyDown(i);
        }
    }

    bool isEmpty() {
        return heap.empty();
    }
    int size() {
        return heap.size();
    }
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue (Max Heap): ";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;
    pq.insert(45);
    pq.insert(20);
    pq.insert(14);
    pq.insert(12);
    pq.insert(31);
    pq.insert(7);
    pq.insert(11);
    pq.insert(13);
    pq.insert(50);
    pq.display();
    cout << "Current size: " << pq.size() << endl;
    cout << "Maximum element: " << pq.getMax() << endl;

    cout << "Extracted: " << pq.extractMax() << endl;
    pq.display();
    cout << "Extracted: " << pq.extractMax() << endl;
    pq.display();
    cout << "Extracted: " << pq.extractMax() << endl;
    pq.display();
    cout << "Current size: " << pq.size() << endl;

    cout << "Changing element at index 2 to value 60" << endl;
    pq.changePriority(2, 60);
    pq.display();
    cout << "Maximum element: " << pq.getMax() << endl;

    pq.remove(1);
    pq.display();

    while (!pq.isEmpty()) {
        cout << "Extracted: " << pq.extractMax() << endl;
    }
    cout << "Current size: " << pq.size() << endl;

    return 0;
}