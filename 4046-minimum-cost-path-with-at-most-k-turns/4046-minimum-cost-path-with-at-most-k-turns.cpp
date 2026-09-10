class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return grid[0][0];

        const long long INF = 1e15;
        vector<vector<long long>> entry(m, vector<long long>(n, INF));
        entry[0][0] = grid[0][0];  

        for (int t = 0; t <= k; ++t) {
            vector<vector<long long>> next(m, vector<long long>(n, INF));
            for (int i = 0; i < m; ++i) {  
                long long run = INF;
                for (int j = 1; j < n; ++j) {
                    run = min(run, entry[i][j - 1]) + grid[i][j];
                    next[i][j] = min(next[i][j], run);
                }
            }
            for (int i = 0; i < m; ++i) { 
                long long run = INF;
                for (int j = n - 2; j >= 0; --j) {
                    run = min(run, entry[i][j + 1]) + grid[i][j];
                    next[i][j] = min(next[i][j], run);
                }
            }
            for (int j = 0; j < n; ++j) {  
                long long run = INF;
                for (int i = 1; i < m; ++i) {
                    run = min(run, entry[i - 1][j]) + grid[i][j];
                    next[i][j] = min(next[i][j], run);
                }
            }
            for (int j = 0; j < n; ++j) { 
                long long run = INF;
                for (int i = m - 2; i >= 0; --i) {
                    run = min(run, entry[i + 1][j]) + grid[i][j];
                    next[i][j] = min(next[i][j], run);
                }
            }
            entry = move(next);
        }
        return entry[m - 1][n - 1] >= INF ? -1 : entry[m - 1][n - 1];
    }
};