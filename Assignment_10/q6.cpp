#include <iostream>
#include <unordered_set>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasDuplicates(TreeNode* root) {
    unordered_set<int> values;

    function<bool(TreeNode*)> traverse = [&](TreeNode* node) -> bool {
        if (node == nullptr) {
            return false;
        }

        if (values.find(node->val) != values.end()) {
            return true; // Duplicate found
        }
        values.insert(node->val);
        if (traverse(node->left) || traverse(node->right)) {
            return true;
        }
        
        return false;
    };
    
    return traverse(root);
}

TreeNode* createTree() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2); 
    
    return root;
}

int main() {
    TreeNode* root = createTree();
    
    if (hasDuplicates(root)) {
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}