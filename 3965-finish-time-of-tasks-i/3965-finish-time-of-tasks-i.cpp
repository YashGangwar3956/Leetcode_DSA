class Solution {
public:
    long long solve(int n,vector<vector<int>>&adj,vector<int>&t){
        if(adj[n].size()==0)return t[n];
         long long mini=LLONG_MAX,maxi=0;
        for(auto&it:adj[n]){
            long long a =solve(it,adj,t);
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
        long long own = (maxi-mini)+t[n];
        long long ft=own+maxi;
        return ft;      
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
        }
       return solve(0,adj,baseTime); 
    }
};