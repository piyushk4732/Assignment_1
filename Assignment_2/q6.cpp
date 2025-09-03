#include <iostream>
using namespace std;

#define MAX 100

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, num;
    Element data[MAX];
};

// (a) Transpose
SparseMatrix transpose(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.data[j].col == i) {
                t.data[k].row = s.data[j].col;
                t.data[k].col = s.data[j].row;
                t.data[k].val = s.data[j].val;
                k++;
            }
        }
    }
    return t;
}
int main() {
    SparseMatrix s = {3, 3, 3, {{0,0,5},{1,1,8},{2,2,9}}};
    SparseMatrix t = transpose(s);
    cout << "Transpose Triplets:\n";
    for (int i = 0; i < t.num; i++) {
        cout << t.data[i].row << " " << t.data[i].col << " " << t.data[i].val << endl;
    }

}