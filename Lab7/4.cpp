#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST.
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    
    if (val < root->val) root->left = insert(root->left, val);
    
    else if (val > root->val) root->right = insert(root->right, val);
    
    return root;
}

void inorder(struct TreeNode* root, int* k, int* result) {
    if (root == NULL || *result != -1) return;

    inorder(root->left, k, result);

    (*k)--;
    if (*k == 0) {
        *result = root->val;
        return;
    }

    inorder(root->right, k, result);
}

// Function to find the Kth smallest element in a BST.
int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;
    inorder(root, &k, &result);
    return result;
}

struct TreeNode* constructBSTFromArray(int* arr, int size) {
    if (size == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) root = insert(root, arr[i]);
    }

    return root;
}

// Function to take level-order input from the user to construct the BST.
struct TreeNode* constructBST() {
    int size;
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = constructBSTFromArray(arr, size);
    free(arr); 
    return root;
}

// Example usage
int main() {
    // Construct the BST
    struct TreeNode* root = constructBST();

    // Get the value of K from the user
    int k;
    scanf("%d", &k);

    // Find the Kth smallest element
    int result = kthSmallest(root, k);

    // Print the result
    printf("%d\n",result);

    return 0;
}
