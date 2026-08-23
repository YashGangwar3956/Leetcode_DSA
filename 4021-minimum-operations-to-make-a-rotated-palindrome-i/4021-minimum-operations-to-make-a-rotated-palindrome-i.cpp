class Solution{
    public:
    int minOperations(string s) {
        int n = s.length(), res = n * 20;
        for (int i = 0; i < n; i++) {
            int cur = i;
            for (int j = 0; j < n / 2; j++) {
                int a = s[(i + j) % n];
                int b = s[(i - j - 1 + n) % n];
                int d = abs(a - b);
                cur += min(d, 26 - d);
                if (cur > res) {
                    break;
                }
            }
            res = min(res, cur);
        }
        return res;
    }
};