class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        ans=max(ans,nums[i]-solve(i+1,nums,dp));
        if(i+1<n)
        ans=max(ans,nums[i]+nums[i+1]-solve(i+2,nums,dp));
        if(i+2<n)
        ans=max(ans,nums[i]+nums[i+1]+nums[i+2]-solve(i+3,nums,dp));
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,stoneValue,dp);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        else return "Tie";
    }
};