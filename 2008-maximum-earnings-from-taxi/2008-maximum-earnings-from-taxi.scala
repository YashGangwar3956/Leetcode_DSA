
object Solution {
    def maxTaxiEarnings(n: Int, rides: Array[Array[Int]]): Long = {
        val arr = rides.sortBy(_(1))

        val m = arr.length

        val ends = new Array[Int](m)

        for (i <- 0 until m) {
            ends(i) = arr(i)(1)
        }

        val dp = Array.fill[Long](m + 1)(0L)

        def bs(t: Int): Int = {
            var l = 0
            var r = m - 1
            var ans = -1

            while (l <= r) {
                val mid = l + (r - l) / 2

                if (ends(mid) <= t) {
                    ans = mid
                    l = mid + 1
                } else {
                    r = mid - 1
                }
            }

            ans
        }

        for (i <- 1 to m) {
            val s = arr(i - 1)(0)
            val e = arr(i - 1)(1)
            val tip = arr(i - 1)(2)

            val prev = bs(s)

            val take = (e - s + tip).toLong + dp(prev + 1)

            dp(i) = math.max(dp(i - 1), take)
        }

        dp(m)
    }
}
