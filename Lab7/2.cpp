#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    if (data == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the maximum depth of the tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to build the tree from array representation
struct TreeNode* buildTree(int arr[], int index, int size) {
    if (index >= size || arr[index] == -1) return NULL;

    struct TreeNode* node = createNode(arr[index]);

    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    node->left = buildTree(arr, leftIndex, size);
    node->right = buildTree(arr, rightIndex, size);

    return node;
}

int main() {
    int n;

    // Input the number of nodes in the tree
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NODES) {
        return 1;
    }

    int treeArray[MAX_NODES];  // input should be in array format (root left_child right_child):

    // Input the tree nodes in array format
    for (int i = 0; i < n; ++i) {
        scanf("%d", &treeArray[i]);
    }

    struct TreeNode* root = buildTree(treeArray, 0, n);

    // TODO: // Calculate and print the maximum depth of the tree
    
    printf("%d\n", maxDepth(root));

    return 0;
}
