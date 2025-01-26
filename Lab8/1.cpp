#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* insertLevelOrder(const std::vector<int>& arr, int i = 0) {
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[i]);

    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);

    return root;
}

void reverseInOrder(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0)
        return;

    reverseInOrder(root->right, k, result);

    if (--k == 0) {
        result = root->val;
        return;
    }

    reverseInOrder(root->left, k, result);
}

int kthLargest(TreeNode* root, int k) {
    int result = -1;
    reverseInOrder(root, k, result);
    return result;
}

int main() {
    int n, k;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    std::cin >> k;

    TreeNode* root = insertLevelOrder(arr);

    std::cout << kthLargest(root, k) << std::endl;

    return 0;
}
