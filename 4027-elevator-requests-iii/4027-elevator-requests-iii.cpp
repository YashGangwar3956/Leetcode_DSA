class Solution {
public:
    long long solve(int mask, int last, int start, int n,
        vector<vector<int>>& req,
        vector<vector<long long>>& dp
    ) {
        int prevMask = mask ^ (1 << last);
        if(prevMask == 0) {
            long long time = abs(start - req[last][1]);
            time = max(time, (long long)req[last][0]);
            return dp[mask][last] = time;
        }
        if(dp[mask][last] != -1) return dp[mask][last];

        long long curRes = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            if(!(prevMask & (1 << i))) continue;
            long long prevTime =solve(prevMask, i, start, n, req, dp);

            long long travel = abs(req[i][1] -req[last][1]);
            long long time = prevTime + travel;
            time = max(time, (long long)req[last][0]);
            curRes = min(curRes, time);
        }
        return dp[mask][last] = curRes;
    }

    long long elevatorRequests(int n, int start,
        vector<vector<int>>& req
    ) {

        int m = req.size();
        vector<vector<long long>> dp(1 << m,
            vector<long long>(m, -1)
        );
        int full = (1 << m) - 1;

        long long res = LLONG_MAX;
        for(int i = 0; i < m; i++) {
            res = min(res, solve(full, i, start, m, req, dp));
        }
        return res;
    }
};