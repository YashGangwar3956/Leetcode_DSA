class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return {0};
        int pref=0,suff=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<int>ans;int pre=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            pre=pref-nums[i];
            suff=sum-pref;
            ans.push_back(abs(pre-suff));
        }
        return ans;
    }
};