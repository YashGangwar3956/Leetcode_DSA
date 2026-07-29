class Solution {
private:
    vector<int> manacher(const vector<int>& seq, int sentinel) {
        int m = seq.size();
        vector<int> s(2 * m + 1, sentinel);
        for (int i = 0; i < m; ++i) {
            s[2 * i + 1] = seq[i];
        }
        int n = s.size();
        vector<int> p(n, 0);
        int c = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (i < r) {
                p[i] = min(r - i, p[2 * c - i]);
            }
            while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && s[i - 1 - p[i]] == s[i + 1 + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
        return p;
    }

public:
    long long getSum(vector<int>& A) {
        int n = A.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + A[i];
        }
        vector<int> p = manacher(A, -1);
        long long res = 0, cur = 0;
        for (int i = 0; i < n + n + 1; ++i) {
            cur = pre[(i + p[i]) / 2] - pre[(i - p[i]) / 2];
            res = max(res, cur);
        }
        return res;
    }
};