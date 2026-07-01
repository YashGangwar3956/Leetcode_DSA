class Solution {
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
    int qx[160005],qy[160005],he,ta;
    int d[405][405],f[160000];
    int get(int x)
    {
        if(f[x]==x)return x;
        return f[x]=get(f[x]);
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(),i,j,k,l;
        memset(d,-1,sizeof(d));
        memset(f,-1,sizeof(f));
        he=ta=0;
        for(i=0;i<n;i++)for(j=0;j<n;j++)if(grid[i][j])
        {
            d[qx[ta]=i][qy[ta]=j]=0;
            ta++;
        }
        while(he!=ta)
        {
            i=qx[he];
            j=qy[he++];
            for(k=0;k<4;k++)if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<n)if(!~d[i+dx[k]][j+dy[k]])
            {
                d[qx[ta]=i+dx[k]][qy[ta]=j+dy[k]]=d[i][j]+1;
                ta++;
            }
        }
        for(l=n*n-1;~l;l--)
        {
            i=qx[l];
            j=qy[l];
            f[i*n+j]=i*n+j;
            for(k=0;k<4;k++)if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<n)if(~f[(i+dx[k])*n+j+dy[k]])f[get((i+dx[k])*n+j+dy[k])]=i*n+j;
            if(~f[0]&&~f[n*n-1]&&get(0)==get(n*n-1))return d[i][j];
        }
        return -1;
    }

};