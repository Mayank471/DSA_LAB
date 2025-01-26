#include <iostream>
#include <vector>
using namespace std;

// Class representing a Tree
class Tree {
public:
    int n;
    vector<vector<int>> adj;

    Tree(int n) : n(n), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Method to calculate the largest number of non-redundant routes
    int calculateMaxRoutes() {
        return n - 1;
    }
};

int main() {
    int n;
    cin >> n;

    Tree tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    cout << tree.calculateMaxRoutes() << endl;

    return 0;
}