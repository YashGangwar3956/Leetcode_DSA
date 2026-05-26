#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, dp(grid, memo, 0, 0, 0));
    }
    int dp(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int r1, int c1, int c2) {
        int n = grid.size();
        int r2 = r1 + c1 - c2;
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (memo[r1][c1][c2] != -1) {
            return memo[r1][c1][c2];
        }
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        int maxCherries = max(dp(grid, memo, r1, c1 + 1, c2), dp(grid, memo, r1 + 1, c1, c2));
        maxCherries = max(maxCherries, dp(grid, memo, r1, c1 + 1, c2 + 1));
        maxCherries = max(maxCherries, dp(grid, memo, r1 + 1, c1, c2 + 1));
        memo[r1][c1][c2] = (maxCherries == INT_MIN) ? INT_MIN : maxCherries + cherries;
        
        return memo[r1][c1][c2];
    }
};