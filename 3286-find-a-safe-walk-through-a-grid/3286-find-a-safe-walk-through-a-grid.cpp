class Solution {
public:
#define p pair<int,pair<int,int>>
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
          int n=grid.size(),m=grid[0].size();
         priority_queue<p>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0]==1) pq.push({health-1,{0,0}});
        else pq.push({health,{0,0}});
        vis[0][0]=1;
         int drow[4]={0,-1,0,1};
         int dcol[4]={-1,0,1,0};
        while(!pq.empty()){
            int h=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row==n-1 && col==m-1 && h>=1)
            return true;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow]    [ncol] && !grid[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({h,{nrow,ncol}});
                }
                else if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  &&  !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    pq.push({h-1,{nrow,ncol}});
                }
            }
        }
        return false;
    }
};