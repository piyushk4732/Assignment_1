#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findFirstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> frequency;

    for (int num : nums) {
        frequency[num]++;
    }

    for (int num : nums) {
        if (frequency[num] == 1) {
            return num;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    int result = findFirstNonRepeating(nums);
    
    if (result != -1) {
        cout << "First non-repeating element: " << result << endl;
    } else {
        cout << "No non-repeating element found" << endl;
    }
    
    return 0;
}