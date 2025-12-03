#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void countFrequency(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (int num : nums) {
        frequency[num]++;
    }

    cout << "Number frequencies:" << endl;
    for (auto& pair : frequency) {
        cout << pair.first << " -> " << pair.second;
        if (pair.second == 1) {
            cout << " time" << endl;
        } else {
            cout << " times" << endl;
        }
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    
    countFrequency(nums);
    
    return 0;
}