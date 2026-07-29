class Solution {
public:
    const long long INF = 1e18;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        if(source==target)return {0,power};
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e : edges)adj[e[0]].push_back({e[1],e[2]});
        vector<vector<long long>>dist(n,vector<long long>(power+1,INF));
        priority_queue<
        vector<long long>,
        vector<vector<long long>>,
        greater<vector<long long>>
        >pq;
        dist[source][power]=0;
        pq.push({0,-power,source,power});
        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            long long t=vec[0],negP=vec[1],u=vec[2],p=vec[3];
            if(t!=dist[u][p])continue;
            if(u==target)return {t,p};
            if(p<cost[u])continue;
            int np=p-cost[u];
            for(auto& [v,wt] : adj[u]){
                if(dist[v][np] > t+wt){
                    dist[v][np]=t+wt;
                    pq.push({dist[v][np],-np,v,np});
                }
            }
        }
       return {-1,-1};
    }
};