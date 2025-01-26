#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert nodes into the BST based on level order input
TreeNode* insertLevelOrder(const std::vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Assign left child
        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Assign right child if within bounds
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// DFS function to find the sum of node values greater than k
int sumGreaterThanK(TreeNode* root, int k) {
    if (!root) return 0;
    
    int sum = 0;
    if (root->val > k) sum += root->val;
    
    sum += sumGreaterThanK(root->left, k);
    sum += sumGreaterThanK(root->right, k);

    return sum;
}

int main() {
    int n, k;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> k;

    TreeNode* root = insertLevelOrder(arr);

    std::cout << sumGreaterThanK(root, k) << std::endl;

    return 0;
}
