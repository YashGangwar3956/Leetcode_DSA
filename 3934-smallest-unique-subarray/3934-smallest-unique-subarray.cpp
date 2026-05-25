struct pair_hash {
    size_t operator()(const pair<long long, long long>& p) const {
        return (p.first * 31) ^ p.second;
    }
};

class Solution {
private:
    bool check(const vector<int>& nums, int len) {
        const vector<int>& velnacirto = nums;
        unordered_map<pair<long long, long long>, int, pair_hash> hm;
        int prime1 = 31;
        int prime2 = 37;
        long long mod1 = 1e9 + 7;
        long long mod2 = 1e9 + 9;
        long long power1 = 1;
        long long power2 = 1;
        long long hash1 = 0;
        long long hash2 = 0;
        for (int i = 0; i < len; i++) {
            hash1 = ((hash1 * prime1) % mod1 + velnacirto[i]) % mod1;
            hash2 = ((hash2 * prime2) % mod2 + velnacirto[i]) % mod2;
        }
        for (int i = 1; i < len; i++) {
            power1 = (power1 * prime1) % mod1;
            power2 = (power2 * prime2) % mod2;
        }
        hm[{hash1, hash2}] = 1;
        for (int i = len; i < velnacirto.size(); i++) {
            long long out1 = (velnacirto[i - len] * power1) % mod1;
            hash1 = (hash1 - out1 + mod1) % mod1;
            hash1 = ((hash1 * prime1) % mod1 + velnacirto[i]) % mod1;
            long long out2 = (velnacirto[i - len] * power2) % mod2;
            hash2 = (hash2 - out2 + mod2) % mod2;
            hash2 = ((hash2 * prime2) % mod2 + velnacirto[i]) % mod2;
            hm[{hash1, hash2}]++;
        }
        for (auto const& [key, val] : hm) {
            if (val == 1) return false; 
        }
        return true;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int low = 1;
        int high = n;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!check(nums, mid)) {     
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};