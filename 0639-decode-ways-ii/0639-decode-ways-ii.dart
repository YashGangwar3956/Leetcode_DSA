
class Solution {
  static const int MOD = 1000000007;

  int numDecodings(String s) {
    int n = s.length;

    List<int> dp = List.filled(n + 2, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') continue;

      int ans = 0;

      if (s[i] == '*') {
        ans = (ans + 9 * dp[i + 1]) % MOD;
      } else {
        ans = (ans + dp[i + 1]) % MOD;
      }

      if (i + 1 < n) {
        if (s[i] == '*') {
          if (s[i + 1] == '*') {
            ans = (ans + 15 * dp[i + 2]) % MOD;
          } else {
            int d = s.codeUnitAt(i + 1) - 48;
            ans = (ans + (d <= 6 ? 2 : 1) * dp[i + 2]) % MOD;
          }
        } else if (s[i] == '1') {
          if (s[i + 1] == '*') {
            ans = (ans + 9 * dp[i + 2]) % MOD;
          } else {
            ans = (ans + dp[i + 2]) % MOD;
          }
        } else if (s[i] == '2') {
          if (s[i + 1] == '*') {
            ans = (ans + 6 * dp[i + 2]) % MOD;
          } else {
            int d = s.codeUnitAt(i + 1) - 48;

            if (d <= 6) {
              ans = (ans + dp[i + 2]) % MOD;
            }
          }
        }
      }

      dp[i] = ans;
    }

    return dp[0];
  }
}
