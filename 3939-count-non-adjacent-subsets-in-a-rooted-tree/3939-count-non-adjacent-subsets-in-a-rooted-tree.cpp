class Solution {
public:
     vector<vector<int>>adj;
    vector<vector<vector<long long>>> dp;
    const int mod =1e9+7;
    void dfs(int u,vector<int>&nums,int k){
        dp[u][0][0]=1;
        dp[u][1][nums[u]%k]=1;
        for(auto v:adj[u]){
            dfs(v,nums,k);
            vector<vector<long long>> dp2(2,vector<long long>(k,0));
            for(int a=0;a<k;++a){
                for(int b=0;b<k;++b){
                    long long x= (dp[v][0][b]%mod+dp[v][1][b]%mod)%mod;
                    dp2[0][(a+b)%k] = (dp2[0][(a+b)%k]%mod+(dp[u][0][a]*x)%mod)%mod;
                }
            }
            for(int a=0;a<k;++a){
                for(int b=0;b<k;++b){
                    dp2[1][(a+b)%k] = (dp2[1][(a+b)%k]%mod+(dp[u][1][a]*dp[v][0][b])%mod)%mod;
                }
            }
            dp[u]=dp2;
        }
    }
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n=parent.size();
        adj.resize(n,{});
        for(int i=0;i<n;++i){
            if(parent[i]!=-1){
                adj[parent[i]].push_back(i);
            }
        }
        dp.resize(n,vector<vector<long long>>(2,vector<long long>(k,0)));
        dfs(0,nums,k);
        long long ans=(dp[0][0][0]+dp[0][1][0]-1+mod)%mod;
        return ans;
    }
};