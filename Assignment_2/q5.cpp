#include <iostream>
using namespace std;

// Diagonal Matrix
class DiagonalMatrix {
    int n;
    int *A;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i - 1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) cout << A[i - 1] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main() {
    DiagonalMatrix dm(3);
    dm.set(1,1,5);
    dm.set(2,2,8);
    dm.set(3,3,9);
    cout << "Diagonal Matrix:" << endl;
    dm.display();
}