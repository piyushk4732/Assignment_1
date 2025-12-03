#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    
    ListNode* current = head;
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;
        }
        visited.insert(current);
        current = current->next;
    }

    return false;
}

ListNode* createListWithCycle() {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; 
    
    return node1;
}

int main() {
    ListNode* head = createListWithCycle();
    
    if (hasCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}