#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void findCommonElements(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA;
    for (int num : A) {
        setA.insert(num);
    }
    cout << "Common elements: ";
    bool first = true;
    for (int num : B) {
        if (setA.count(num) > 0) {
            if (!first) {
                cout << ", ";
            }
            cout << num;
            first = false;
            setA.erase(num);
        }
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    
    findCommonElements(A, B);
    
    return 0;
}