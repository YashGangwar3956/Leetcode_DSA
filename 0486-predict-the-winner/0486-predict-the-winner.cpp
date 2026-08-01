class Solution {
public:
    int solve(int i ,int j,vector<int>& nums,int turn,vector<vector<int>>&dp){
if(i==nums.size() || j==-1)return 0;
if(i>j)return 0;
if(dp[i][j]!=-1)
return dp[i][j];
if(turn==0){
return dp[i][j]=max(nums[i]+solve(i+1,j,nums,1,dp),
                    nums[j]+solve(i,j-1,nums,1,dp));}
else{
return dp[i][j]=min(-nums[i]+solve(i+1,j,nums,0,dp),-nums[j]+solve(i,j-1,nums,0,dp));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int val=solve(0,n-1,nums,0,dp);
        return val>=0;
    }
};