#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (dist[j][i] != INT_MAX && dist[i][k] != INT_MAX) 
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

    int minReachable = n, resultCity = -1;
    for (int i = 0; i < n; i++) {
        int reachableCount = 0;

        for (int j = 0; j < n; ++j) if (i != j && dist[i][j] <= distanceThreshold) reachableCount++;
        
        if (reachableCount < minReachable || (reachableCount == minReachable && i > resultCity)) {
            minReachable = reachableCount;
            resultCity = i;
        }
    }  
    return resultCity;
}

int main() {
    int n, m, distanceThreshold;
    cin >> n >> m >> distanceThreshold;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; ++i) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int resultCity = findTheCity(n, edges, distanceThreshold);
    cout << resultCity << endl;

    return 0;
}
