#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, high, key);
    else return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {11, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;
    cout << "Iterative: Index = " << binarySearchIterative(arr, n, key) << endl;
    cout << "Recursive: Index = " << binarySearchRecursive(arr, 0, n - 1, key) << endl;
    return 0;
}