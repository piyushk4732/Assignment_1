#include <iostream>
using namespace std;
class HeapSort {
private:
    void heapify(int arr[], int n, int i) {
        int largest = i;      
        int left = 2 * i + 1; 
        int right = 2 * i + 2;  

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapifyMin(int arr[], int n, int i) {
        int smallest = i;    
        int left = 2 * i + 1;   
        int right = 2 * i + 2; 

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyMin(arr, n, smallest);
        }
    }

public:
    void heapSortIncreasing(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void heapSortDecreasing(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMin(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMin(arr, i, 0);
        }
    }

    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    HeapSort sorter;

    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    cout << "Original array: ";
    sorter.printArray(arr1, n1);
  
    sorter.heapSortIncreasing(arr1, n1);
    cout << "Sorted in Increasing order: ";
    sorter.printArray(arr1, n1);
 
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    sorter.heapSortDecreasing(arr2, n2);
    cout << "Sorted in Decreasing order: ";
    sorter.printArray(arr2, n2);

    return 0;
}