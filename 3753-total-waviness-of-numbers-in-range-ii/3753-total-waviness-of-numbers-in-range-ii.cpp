class Solution {
public:
    int n;
    string s;
    long long dpWays[2][2][3][10][16];
    long long dpContrib[2][2][3][10][16];
    pair<long long, long long> solve(bool tight, bool allZeros, int sign, int last, int i) {
        if (i == n) return {1, 0};
        if (dpWays[tight][allZeros][sign][last][i] != -1) {
            return { dpWays[tight][allZeros][sign][last][i],
                     dpContrib[tight][allZeros][sign][last][i] };
        }
        long long ways = 0;
        long long contrib = 0;
        int limit = tight ? (s[i] - '0') : 9;
        for (int d = 0; d <= limit; ++d) {
            int new_sign = 0;
            if (!allZeros) {
                if (last > d) new_sign = 1;
                else if (last < d) new_sign = 2;
            }
            bool nextAllZeros = allZeros && (d == 0);
            auto child = solve(tight && (d == limit), nextAllZeros, new_sign, d, i + 1);
            long long subWays = child.first;
            long long subContrib = child.second;
            if ((sign == 1 && last < d) || (sign == 2 && last > d)) {
                contrib += subWays;    
            }
            contrib += subContrib;
            ways += subWays;
        }
        dpWays[tight][allZeros][sign][last][i] = ways;
        dpContrib[tight][allZeros][sign][last][i] = contrib;
        return {ways, contrib};
    }
    long long totalWaviness(long long num1, long long num2) {
        auto compute = [&](long long x) -> long long {
            if (x < 0) return 0;
            s = to_string(x);
            n = s.length();
            memset(dpWays, -1, sizeof(dpWays));
            memset(dpContrib, -1, sizeof(dpContrib));
            auto ans = solve(true, true, 0, 0, 0);
            return ans.second;
        };
        long long up = compute(num2);
        long long lo = compute(num1 - 1);
        return up - lo;
    }
};