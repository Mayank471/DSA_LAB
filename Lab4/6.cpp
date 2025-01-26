#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode *left, *right;
    int height;
    TreeNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// Utility function to get maximum of two integers
int max(int a,int b) {
    return (a>b) ? a : b;
}

// Function to get height of the tree
int height(TreeNode *N) {
    return (N==nullptr) ? 0 : N->height;
}

// Helper function to create a new node with the given key
TreeNode* newNode(int key) {
    return new TreeNode(key);
}

// Function to right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Function to left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Get Balance factor of node N
int getBalance(TreeNode *N) {
    if (N ==nullptr) return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)){
            TreeNode *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            delete temp;
            }
        } else {
            TreeNode* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        }
    if (root == nullptr) {
        return root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(TreeNode *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
    TreeNode *root = NULL;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }
    cin >> key;
    root = deleteNode(root, key);
    preOrder(root);
    return 0;
}
