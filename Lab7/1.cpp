#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Node structure for the binary tree.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BT {
private:
    TreeNode* root;

    // Helper function to build the tree from inorder and preorder traversals.
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder,
                        unordered_map<int, int>& inorderMap,
                        int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return nullptr;

        int currentVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(currentVal);

        if (inStart == inEnd) return node;

        int inIndex = inorderMap[currentVal];

        node->left = buildTree(inorder, preorder, inorderMap, inStart, inIndex - 1, preIndex);
        node->right = buildTree(inorder, preorder, inorderMap, inIndex + 1, inEnd, preIndex);

        return node;
    }

    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            } 
            else result.push_back(-1);
        }

        int i = result.size() - 1;
        while (i >= 0 && result[i] == -1) {
            result.pop_back();
            i--;
        }

        for (int val : result) cout << val << " ";
        cout << endl;
    }

public:
    BT() : root(nullptr) {}

    void make_BT_from_pre_in(int n, vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < n; ++i) inorderMap[inorder[i]] = i;

        int preIndex = 0;
        root = buildTree(inorder, preorder, inorderMap, 0, n - 1, preIndex);

        levelOrderTraversal(root);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    BT tree;
    tree.make_BT_from_pre_in(n, preorder, inorder);

    return 0;
}
