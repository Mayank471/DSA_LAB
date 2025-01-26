#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
    int n; // number of nodes
    unordered_map<int, vector<pii>> adjList; // adjacency list (node -> [(neighbor, weight)])

public:
    // Constructor initializes the graph with given number of nodes and edges
    Solution(int numVertices, vector<vector<int>>& edges) {
        n = numVertices;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
        }
    }

    // Function to calculate the minimum time for all nodes to receive the signal
    int networkDelayTime(int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n + 1, INT_MAX); 

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist > dist[u]) continue;

            for (auto [v, w] : adjList[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    Solution solution(n, edges);
    cout << solution.networkDelayTime(k) << endl;
    
    return 0;
}
