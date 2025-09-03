#include <iostream>
using namespace std;

// Linear Search
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return -1;
}

// Binary Search
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // missing 4
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing (Binary): " << findMissingBinary(arr, n) << endl;

}