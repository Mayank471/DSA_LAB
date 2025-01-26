#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a new tree node
TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to build a binary tree from an array
TreeNode* buildTreeFromArray(const vector<int>& arr, int index) {
    if (index >= arr.size() || arr[index] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[index]);
    root->left = buildTreeFromArray(arr, 2 * index + 1);
    root->right = buildTreeFromArray(arr, 2 * index + 2);
    return root;
}

// Function to check if two binary trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Function to build a binary tree from a string in the array format
TreeNode* buildTreeFromArrayString(const string& str) {
    vector<int> arr;
    stringstream s(str);
    int value;
    while (s >> value) {
        arr.push_back(value);
        if (s.peek() == ' ') {
            s.ignore();
        }
    }
    return buildTreeFromArray(arr, 0);
}

void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    // Get the array input for the first tree from the user
    string input1;
    getline(cin, input1);

    // Create binary tree from the first input
    TreeNode* root1 = buildTreeFromArrayString(input1);

    // Get the array input for the second tree from the user
    string input2;
    getline(cin, input2);

    // Create binary tree from the second input
    TreeNode* root2 = buildTreeFromArrayString(input2);

    // Check if the trees are identical
    if (areIdentical(root1, root2)) {
        cout << "1"; // 1 for identical
    } else {
        cout << "0"; // 0 for not identical
    }

    // Free allocated memory
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}
