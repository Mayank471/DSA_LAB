#include <iostream>
#include <vector>
#include <algorithm>

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class DisjointSet {
private:
    std::vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initialize each node as its own parent
        }
    }

    // Find function with path compression
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Graph {
private:
    int V;
    std::vector<Edge> edges;
public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    // Function to find the MST using Kruskal's algorithm
    void kruskalMST() {
        std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DisjointSet ds(V);
        std::vector<Edge> mst;
        int totalWeight = 0;

        for (const auto &edge : edges) {
            if (ds.find(edge.u) != ds.find(edge.v)) {
                ds.unite(edge.u, edge.v);
                mst.push_back(edge);
                totalWeight += edge.weight;
            }
        }

        // Print the MST edges
        for (const auto& edge : mst) {
            std::cout << edge.u << " " << edge.v << " " << edge.weight << std::endl;
        }

        // Print the total weight of the MST
        std::cout << totalWeight << std::endl;
    }
};

int main() {
    int V, E;
    std::cin >> V >> E;
    Graph graph(V);

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.kruskalMST();
    return 0;
}
