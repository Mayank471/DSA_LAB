#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> floydWarshall(int V, const vector<tuple<int, int, int>> &edges) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i) dist[i][i] = 0;

    for (const auto &edge : edges) {
        int u = get<0>(edge) - 1;  
        int v = get<1>(edge) - 1; 
        int w = get<2>(edge);
        dist[u][v] = w;
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                dist[i][j] = -1; 
            } else if (dist[i][j] <= 0) dist[i][j] = 0;
        }
    }
    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
    }

    vector<vector<int>> result = floydWarshall(V, edges);

    for (const auto &row : result) {
        for (int cost : row) {
            cout << cost << " ";
        }
        cout << "\n";
    }
    return 0;
}
