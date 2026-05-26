class Solution:
    def cherryPickup(self, grid):
        n = len(grid)
        memo = [[[-1] * n for _ in range(n)] for _ in range(n)]
        return max(0, self.dp(grid, memo, 0, 0, 0))
    def dp(self, grid, memo, r1, c1, c2):
        n = len(grid)
        r2 = r1 + c1 - c2
        if r1 >= n or r2 >= n or c1 >= n or c2 >= n or grid[r1][c1] == -1 or grid[r2][c2] == -1:
            return float('-inf')
        if memo[r1][c1][c2] != -1:
            return memo[r1][c1][c2]
        if r1 == n - 1 and c1 == n - 1:
            return grid[r1][c1]
        cherries = grid[r1][c1] if r1 == r2 and c1 == c2 else grid[r1][c1] + grid[r2][c2]
        maxCherries = max(self.dp(grid, memo, r1, c1 + 1, c2), self.dp(grid, memo, r1 + 1, c1, c2))
        maxCherries = max(maxCherries, self.dp(grid, memo, r1, c1 + 1, c2 + 1))
        maxCherries = max(maxCherries, self.dp(grid, memo, r1 + 1, c1, c2 + 1))
        memo[r1][c1][c2] = maxCherries if maxCherries == float('-inf') else maxCherries + cherries
        return memo[r1][c1][c2]