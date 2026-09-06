class Solution {
public:
   int solve(int i,int j,string s,string t,vector<vector<int>>&dp){
    if(j==t.size())return 1;
    if(i==s.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int take=0;
    if(s[i]==t[j]){
       take=solve(i+1,j+1,s,t,dp);
    }
    int not_take=solve(i+1,j,s,t,dp);
    return dp[i][j]=take+not_take;
   }
   int solveTab(string s,string t){
        int n=s.size();int m=t.size();
        int mod=1e9+7;
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long take=0;
             if(s[i]==t[j]){
             take=dp[i+1][j+1];
            }
            long long not_take=dp[i+1][j];
            dp[i][j]=(take%mod+not_take%mod)%mod;
            }
            }
        return dp[0][0];
   }
   int solveTabOptimized(string s,string t){
    int n = s.size();
    int m = t.size();
    const int mod = 1e9 + 7;

    vector<long long> dp(m + 1, 0);
    dp[m] = 1;

    for (int i = n - 1; i >= 0; --i) {
        vector<long long> new_dp(m + 1, 0);
        new_dp[m] = 1;
        for (int j = m - 1; j >= 0; --j) {
            long long take = 0;
            if (s[i] == t[j]) {
                take = dp[j + 1];
            }
            long long not_take = dp[j];
            new_dp[j] = (take + not_take) % mod;
        }
        dp = new_dp;
    }

    return dp[0];

   }
    int numDistinct(string s, string t) {
        int n=s.size();int m=t.size();
        return solveTabOptimized(s,t);
    }
};