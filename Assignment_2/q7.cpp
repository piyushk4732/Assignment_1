#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    long long count = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            count += (n1 - i); 
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    return count;
}

long long countInversions(int arr[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = (l + r) / 2;
        count += countInversions(arr, l, m);
        count += countInversions(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}
int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of inversions: " << countInversions(arr, 0, n - 1) << endl;
}
