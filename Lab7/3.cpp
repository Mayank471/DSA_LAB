#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    if (value == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    if (index >= size || arr[index] == -1) return NULL;

    struct TreeNode* root = createNode(arr[index]);

    root->left = buildTreeFromArray(arr, 2 * index + 1, size);
    root->right = buildTreeFromArray(arr, 2 * index + 2, size);

    return root;
}

struct TreeNode* getNode(struct TreeNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->value == value) return root;

    struct TreeNode* leftSearch = getNode(root->left, value);
    if (leftSearch != NULL) return leftSearch;

    return getNode(root->right, value);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* n1, struct TreeNode* n2) {
    if (root == NULL) return NULL;

    if (root == n1 || root == n2) return root;

    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, n1, n2);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int size;
    // Enter the size of the array representing the binary tree:
    scanf("%d", &size);

    int arr[size];
    // Enter the elements in level order fashion (enter -1 for NULL nodes):
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTreeFromArray(arr, 0, size);

    // Take User given values of the nodes for which to find the Lowest Common Ancestor: 
    
    int node1, node2;
    
    scanf("%d %d", &node1, &node2);

    struct TreeNode* n1 = getNode(root, node1);
    struct TreeNode* n2 = getNode(root, node2);

    if (n1 != NULL && n2 != NULL) {
        struct TreeNode* result = lowestCommonAncestor(root, n1, n2);
        printf("%d\n", result->value);
    } else {
        //printf("Invalid node values entered.\n");
    }

    return 0;
}
