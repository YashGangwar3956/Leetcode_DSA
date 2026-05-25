class Solution {
    fun maxCoins(nums: IntArray): Int {
        val n = nums.size + 2
        val dp = Array(n) { IntArray(n) }
        val a = IntArray(n) { 1 }

        var idx = 1
        for (x in nums) {
            a[idx++] = x
        }

        for (len in 2..n) {
            var i = 0
            while (i <= n - len) {
                val j = i + len - 1

                var k = i + 1
                while (k < j) {
                    dp[i][j] = maxOf(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]
                    )
                    k++
                }
                i++
            }
        }

        return dp[0][n - 1]
    }
}