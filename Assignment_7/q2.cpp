#include <iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int minIndex = i;
        int maxIndex = i;
        for (int k = i; k <= j; k++) {
            if (arr[k] < arr[minIndex]) {
                minIndex = k;
            }
            if (arr[k] > arr[maxIndex]) {
                maxIndex = k;
            }
        }
        swap(arr[i], arr[minIndex]);
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        swap(arr[j], arr[maxIndex]);
        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    cout << endl;
    
    improvedSelectionSort(arr, n);
    
    cout << "\nFinal sorted array: ";
    printArray(arr, n);
    
    return 0;
}