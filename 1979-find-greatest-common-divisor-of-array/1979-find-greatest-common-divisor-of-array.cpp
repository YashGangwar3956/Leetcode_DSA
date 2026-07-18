class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end()),maxi=*max_element(nums.begin(),nums.end());
   return __gcd(mini,maxi);
    }
};