#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    // Constructor to initialize a new AVL tree node
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;  // New node is initially at height 1
    }
};

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to create a new AVL tree node
TreeNode* createNode(int data) {
        return new TreeNode(data);
}

// Function to right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Function to left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// Get Balance factor of node N
int getBalance(TreeNode* N) {
    if(N==nullptr) return 0;
    return getHeight(N->left)-getHeight(N->right);
}

// Function to insert a node in AVL tree and balance the tree
TreeNode* insert(TreeNode* node, int data) {
    if (node == nullptr) return new TreeNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(TreeNode* root) {
    if(root==nullptr) return true;
    int val= getBalance(root);
    if(abs(val)>1){
        return false;
    }
    return isValidAVL(root->left) && isValidAVL(root->right);
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(TreeNode* root) {
    if(root!= nullptr) {
        cout<<root->data <<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
