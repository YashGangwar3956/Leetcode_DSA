class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>vis(n+1,0);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                ans=min(ans,i.second);
                if(!vis[i.first]){
                    vis[i.first]=1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};