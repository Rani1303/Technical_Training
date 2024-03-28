#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != nullptr || !stk.empty()) {
        while (current != nullptr) {
            cout << current->val << " ";
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        current = current->right;
    }
}

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

int main() {
    TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->left = newNode(3);
    root->right->right->left->right = newNode(4);
    root->right->right->right = newNode(6);

    cout << "Preorder Traversal: ";
    preOrder(root);
    return 0;
}
