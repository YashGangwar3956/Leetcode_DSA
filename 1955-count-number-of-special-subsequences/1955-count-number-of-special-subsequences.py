class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        dp = [1, 0, 0, 0]
        for num in nums:
            idx = num + 1
            dp[idx] += (dp[idx] + dp[idx-1]) 
            dp[idx] = dp[idx] % MOD
        return dp[-1]