#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int val) {
        if (node==nullptr) return new TreeNode(val);

        if(val<node->data) node->left=insert(node->left,val);
        else node->right=insert(node->right,val);
        return node;
    }
    void inOrder(TreeNode* node, vector<int>& result) {
        if (node==nullptr) {
            return;
        }
        inOrder(node->left, result);
        result.push_back(node->data);
        inOrder(node->right, result);
    }
    public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }
    vector<int> inOrderTraversal() {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    BST bst;

    for (int i=0;i<n;i++) {
        int value;
        cin>>value;
        bst.insert(value);
        }

    vector<int> inOrder = bst.inOrderTraversal();

    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
