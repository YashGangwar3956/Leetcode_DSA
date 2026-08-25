class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int x = k;  
        for (auto i : nums) {
            if (i == x) x += k;
        }
        return x;
    }
};