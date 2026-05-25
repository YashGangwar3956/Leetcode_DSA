class Solution {
public:
    using ll = long long;
    ll calc(vector<int>& v, int x, int k) {
        ll cost = 0;
        for (int a : v) {
            int r = a % k;
            int d = abs(r - x);
            cost += min(d, k - d);
        }
        return cost;
    }
    int minOperations(vector<int>& nums, int k) {
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        int K = k;
        vector<ll> A(K, 0), B(K, 0); 
        for (int x = 0; x < K; x++) {
            A[x] = calc(even, x, K);
            B[x] = calc(odd, x, K);
        }
        ll best1 = LLONG_MAX, best2 = LLONG_MAX;
        int id1 = -1;
        for (int i = 0; i < K; i++) {
            if (B[i] < best1) {
                best2 = best1;
                best1 = B[i];
                id1 = i;
            } else if (B[i] < best2) {
                best2 = B[i];
            }
        }
        ll ans = LLONG_MAX;
        for (int x = 0; x < K; x++) {
            ll bestBExceptX = (x == id1 ? best2 : best1);
            ans = min(ans, A[x] + bestBExceptX);
        }

        return (int)ans;
    }
};