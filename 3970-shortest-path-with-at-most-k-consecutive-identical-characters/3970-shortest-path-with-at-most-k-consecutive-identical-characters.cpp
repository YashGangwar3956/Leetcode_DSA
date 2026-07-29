class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(edges.size() == 0 && n == 1){
            return 0;
        }
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>>pq; // distance,node,cnt
        // unordered_map<int,vector<pair<int,int>>>adj;
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<long long>>dp(n,vector<long long>(k+1,LLONG_MAX));
        int ans = INT_MAX;

        for(int i=0;i<edges.size();i++){
            int ele1 = edges[i][0];
            int ele2 = edges[i][1];
            int cost = edges[i][2];

            adj[ele1].push_back({ele2,cost});
        }

        pq.push({0,0,1}); // distance , node , cnt
        dp[0][1] = 0;

        while(!pq.empty()){
            auto[dist,node,cnt] = pq.top();
            pq.pop();

            if(dist > dp[node][cnt]){
                continue;
            }

            if(node == n-1){
                return dist;
            }

            for(auto i:adj[node]){
                int ele = i.first;
                int cost = i.second;
                int newcnt;

                if(labels[node] == labels[ele]){
                    newcnt = cnt+1;
                }
                else{
                    newcnt = 1;
                }

                if(newcnt > k){
                    continue;
                }

                long long newdist = (long long) cost + dist;

                if(newdist < dp[ele][newcnt]){
                    dp[ele][newcnt] = newdist;
                    pq.push({newdist,ele,newcnt});
                }
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};