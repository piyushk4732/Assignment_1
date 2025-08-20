#include <iostream>
using namespace std;
int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    int arr[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += arr[i][j];
        }
        cout<< rowSum << endl;
    }
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += arr[i][j];
        }
        cout<< colSum << endl;
    }
    return 0;
}
