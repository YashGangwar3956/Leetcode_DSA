class Solution {
    #define ll long long

    ll gcd(ll a, ll b){
        if(b == 0) return a;
        if(b > a) return gcd(b, a);
        return gcd(b, a % b);
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefixGcd(n);

        int maxi = -1;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int l = 0, r = n - 1;
        ll ans = 0;

        while(l < r){
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};