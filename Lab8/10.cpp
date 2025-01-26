#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
class Solution {
    set<pii> Edges;
    int n;
public:
    Solution(int numVertices, set<pii>& E) {
        // Constructor initializes the graph
        n = numVertices;
        Edges = E;
    }

    bool isValidEdge(pii e) {
        return Edges.find(e) != Edges.end();
    }

    bool verifyHamiltonianCycle(vector<int>& seq) {
        if (seq.size() != n + 1) return false;

        if (seq.front() != seq.back()) return false;

        set<int> visited;
        for (int i = 0; i < n; i++) {
            int u = seq[i];
            int v = seq[i + 1];

            if (!isValidEdge({u, v}) && !isValidEdge({v, u})) return false;

            if (visited.find(u) != visited.end()) return false;
            visited.insert(u);
        }
        return visited.size() == n;
    }
};

int main() {
    int n, m; cin >> n >> m;
    set<pii> E;
    while (m--) {
        int u, v;
        cin >> u >> v;
        E.insert({u, v});
        E.insert({v, u});
    }
    int tt;cin >> tt;
    while (tt--) {
        int w; cin >> w;
        vector<int> seq(w, 0); for (int i = 0; i < w; i++) cin >> seq[i];
        Solution sol(n, E);
        
		bool ans = sol.verifyHamiltonianCycle(seq);
        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}
