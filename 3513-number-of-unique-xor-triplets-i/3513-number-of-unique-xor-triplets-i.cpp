class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int nearest = (int)(log(n)/log(2));
        return 1 << (nearest + 1);
    }
};