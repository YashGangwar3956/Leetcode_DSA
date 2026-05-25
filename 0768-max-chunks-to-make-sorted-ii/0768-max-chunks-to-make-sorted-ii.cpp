#define ll long long int
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<ll, ll> mp;
        for (auto x : arr) {
            mp[x]++;
        }
        ll sum = 0;
        ll i = 0, chunk = 0;
        for (auto &[r, c] : mp) {
            while (c > 0) {
                sum += (r - arr[i++]);
                if (sum == 0) {
                    chunk++;
                }
                c--;
            }
        }
        return (int) chunk;
    }
};