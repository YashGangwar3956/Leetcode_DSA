class Solution:
    def __init__(self):
        self.adj = {
            1: [2, 3, 4, 5, 6],
            2: [1, 3, 5],
            3: [1, 2, 4, 5],
            4: [1, 3, 5],
            5: [1, 2, 3, 4, 6],
            6: [1, 5]
        }
        self.MOD = 10**9 + 7
        self.dp = None

    def distinctSequences(self, n: int) -> int:
        self.dp = [[[-1 for _ in range(n + 1)] for _ in range(7)] for _ in range(7)]
        ans = 0
        for i in range(1, 7):
            ans = (ans + self.count(i, 0, n)) % self.MOD
        return ans

    def count(self, curr: int, prev: int, n: int) -> int:
        if n == 1:
            return 1  
        if self.dp[curr][prev][n] != -1:
            return self.dp[curr][prev][n]
        ans = 0
        for next_roll in self.adj[curr]:
            if next_roll == prev: 
                continue
            ans = (ans + self.count(next_roll, curr, n - 1)) % self.MOD
        self.dp[curr][prev][n] = ans  
        return ans