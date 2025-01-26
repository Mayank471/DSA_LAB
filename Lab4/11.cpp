#include <iostream>
using namespace std;

// Class definition for a Node in the BST
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    TreeNode* root;

    // Helper function to insert a node in the BST
    TreeNode* insert(TreeNode* node, int data) {
        // TODO: Implement the insert function
        if (node==nullptr)  return new TreeNode(data);
        
        if (data<node->data)node->left =insert(node->left, data);
        else node->right=insert(node->right, data);
        return node;
    }

    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        // TODO: Implement the findMin function
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to find a node with a given value
    TreeNode* findNode(TreeNode* node, int data) {
        // TODO: Implement the findNode function
        if (node ==nullptr||node->data == data) {
            return node;
        }
        if (data < node->data) return findNode(node->left, data);
        else return findNode(node->right, data);
    }

public:
    // Constructor to initialize the root of the BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data) {
        root = insert(root, data);
    }

    // Function to find the in-order successor of a given node
    int findInOrderSuccessor(int data) {
        // TODO: Implement the findInOrderSuccessor function
        TreeNode* current = findNode(root, data);
        if (current == nullptr) {
            return -1;
        }
        if (current->right != nullptr) {
            TreeNode* successor = findMin(current->right);
            return successor->data;
        }
        TreeNode* successor = nullptr;
        TreeNode* ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        return (successor != nullptr) ? successor->data : -1;
    }
};

// Main function to execute the program
int main() {
    int n, target;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> target; 

    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
