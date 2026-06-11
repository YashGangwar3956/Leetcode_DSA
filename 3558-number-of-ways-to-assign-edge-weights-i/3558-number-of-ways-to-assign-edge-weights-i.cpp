class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxHeight = 0;

    // Fast exponentiation: computes (base^exp) % MOD
    long long powerMod(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    // DFS to find the height of the tree
    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        maxHeight = max(maxHeight, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

    // Assigns weights based on the max depth of the tree
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1); // 1-based indexing

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        maxHeight = 0;
        dfs(1, -1, 0, adj); // Assuming root is node 1

        if (maxHeight == 0) return 1; // Tree with single node

        return powerMod(2, maxHeight - 1);  //think once, why this?
    }
};

