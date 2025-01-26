#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree( vector<int>& arr) {
    if (arr.empty()||arr[0] == -1) return nullptr;
    TreeNode* root=new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < arr.size()) {
        TreeNode* current=q.front();
        q.pop();
        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;
        if (i >= arr.size()) break;
        if (arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
int checkHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;  // Tree is not balanced
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout <<"false"<< endl;
    } else {
        TreeNode* root = constructTree(arr);
        cout << (isBalanced(root) ? "true" : "false") << endl;
    }
    return 0;
}
