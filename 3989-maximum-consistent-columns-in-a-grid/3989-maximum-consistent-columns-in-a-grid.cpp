class Solution {
public:
       int maxConsistentColumns(vector<vector<int>>& A, int limit) {
        int n = A[0].size();
        vector<int> dp(n, 1);
        for (int b = 0; b < n; ++b) {
            for (int a = 0; a < b; ++a) {
                if (dp[a] + 1 > dp[b]) {
                    bool ok = true;
                    for (const auto& r : A) {
                        if (abs(r[b] - r[a]) > limit) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        dp[b] = dp[a] + 1;
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};