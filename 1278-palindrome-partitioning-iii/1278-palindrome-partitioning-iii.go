
func palindromePartition(s string, k int) int {
	n := len(s)

	dp := make([][]int, 101)
	pd := make([][]int, 101)

	for i := 0; i < 101; i++ {
		dp[i] = make([]int, 101)
		pd[i] = make([]int, 101)

		for j := 0; j < 101; j++ {
			dp[i][j] = 100
			pd[i][j] = 101
		}
	}

	for i := 0; i < n; i++ {
		pd[i][i] = 0
	}

	for i := 0; i < n-1; i++ {
		if s[i] == s[i+1] {
			pd[i][i+1] = 0
		} else {
			pd[i][i+1] = 1
		}
	}

	for length := 2; length < n; length++ {
		for i := 0; i < n; i++ {
			if i+length >= n {
				continue
			}

			j := i + length

			pd[i][j] = pd[i+1][j-1]

			if s[i] != s[j] {
				pd[i][j] = pd[i+1][j-1] + 1
			}
		}
	}

	for j := 0; j < n; j++ {
		dp[j][1] = pd[0][j]
	}

	for kk := 2; kk <= k; kk++ {
		for j := 1; j < n; j++ {
			dp[j][kk] = j + 1

			for l := 0; l <= j; l++ {
				val := dp[l][kk-1] + pd[l+1][j]

				if val < dp[j][kk] {
					dp[j][kk] = val
				}
			}
		}
	}

	return dp[n-1][k]
}
