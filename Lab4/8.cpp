#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(): data(0), left(nullptr), right(nullptr) {}

        Node(int val): data(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void make_BT_from_array(int *arr, int size) {
        this->root = BT_from_level_order_array(arr, 0, size);
    }

    Node* BT_from_level_order_array(int *arr, int index, int size) {
        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }

    void alternatingLevelOrderTraversal() {
        // Implement logic for alternating level order traversal here
        if(!root) return;
        deque<Node*> currentLevel;
        currentLevel.push_back(root);
        bool leftToRight = true;
        while (!currentLevel.empty()) {
            int LevelCount = currentLevel.size();
            vector<int> levelNodes(LevelCount);

            for (int i = 0; i < LevelCount; i++) {
                Node* node = currentLevel.front();
                currentLevel.pop_front();
                levelNodes[i] = node->data;
                if (node->left) currentLevel.push_back(node->left);
                if (node->right) currentLevel.push_back(node->right);
            }

            if (!leftToRight) {
                reverse(levelNodes.begin(), levelNodes.end());
            }

            for (int i = 0; i < LevelCount; ++i) {
                cout << levelNodes[i] << " ";
            }
            cout << "| ";

            leftToRight = !leftToRight;
        }
    }
};

int main() {
    BinaryTree tree;
    int n, data;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> data;
        arr[i] = data;
    }

    tree.make_BT_from_array(arr, n);
    tree.alternatingLevelOrderTraversal();
    delete[] arr;
    return 0;
}
