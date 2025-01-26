#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph {
private:
    int n;
    unordered_map<int, unordered_set<int>> adj;

public:
    Graph(int n) : n(n) {}

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    bool isEulerianCycle(const vector<int>& sequence) {
        int w = sequence.size();
        
        if (sequence[0] != sequence[w - 1]) return false;

        unordered_map<int, unordered_map<int, int>> edge_count;

        for (int i = 0; i < w - 1; i++) {
            int u = sequence[i];
            int v = sequence[i + 1];

            if (adj[u].find(v) == adj[u].end()) return false;

            edge_count[u][v]++;
            edge_count[v][u]++;

            if (edge_count[u][v] > 1) return false;
        }

        for (auto& edges : adj) {
            int u = edges.first;
            for (int v : edges.second) {
                if (edge_count[u][v] != 1) return false;
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int w;
        cin >> w;
        vector<int> sequence(w);

        for (int j = 0; j < w; j++) {
            cin >> sequence[j];
        }
        if (graph.isEulerianCycle(sequence)) cout << "YES" << endl;
        
        else cout << "NO" << endl;
    }

    return 0;
}
