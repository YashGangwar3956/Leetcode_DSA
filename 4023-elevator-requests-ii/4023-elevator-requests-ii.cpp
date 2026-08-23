

class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long solve(int l, int r, int right, int rem, vector<int>& req) {
        if (rem == 0)
            return 0;

        long long &ans = dp[l][r][right];

        if (ans != -1)
            return ans;

        ans = LLONG_MAX / 4;

        if (right) {

            if (l > 0) {
                long long dist = req[r] - req[l - 1];

                ans = min(ans,
                    rem * dist +
                    solve(l - 1, r, 0, rem - 1, req)
                );
            }

            if (r + 1 < (int)req.size()) {
                long long dist = req[r + 1] - req[r];

                ans = min(ans,
                    rem * dist +
                    solve(l, r + 1, 1, rem - 1, req)
                );
            }
        }
        else {

            if (l > 0) {
                long long dist = req[l] - req[l - 1];

                ans = min(ans,
                    rem * dist +
                    solve(l - 1, r, 0, rem - 1, req)
                );
            }

            if (r + 1 < (int)req.size()) {
                long long dist = req[r + 1] - req[l];

                ans = min(ans,
                    rem * dist +
                    solve(l, r + 1, 1, rem - 1, req)
                );
            }
        }

        return ans;
    }

    long long elevatorRequests(int n, int start, vector<int>& requests) {

        vector<int> req;

        for (int x : requests) {
            if (x != start)
                req.push_back(x);
        }

        req.push_back(start);

        sort(req.begin(), req.end());

        int m = req.size();

        int rem = m - 1;

        dp.assign(
            m,
            vector<vector<long long>>(
                m,
                vector<long long>(2, -1)
            )
        );

        int idx = lower_bound(req.begin(), req.end(), start) - req.begin();

        if (rem == 0)
            return 0;

        long long ans = LLONG_MAX;

        if (idx > 0) {
            ans = min(ans, solve(idx, idx, 0, rem, req));
        }

        if (idx + 1 < m) {
            ans = min(ans, solve(idx, idx, 1, rem, req));
        }

        return ans;
    }
};