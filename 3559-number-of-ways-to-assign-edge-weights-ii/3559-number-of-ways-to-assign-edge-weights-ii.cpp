class segmentTree{
  public:
    vector<int>seg;
    segmentTree(int n=0){
        seg.resize(n*4);
    }
    void build(int i,int l,int h,vector<int>&nums){
        if(l==h){
            seg[i]=nums[l];
            return;
        }
        int mid=(l+h)/2;
        build(i*2+1,l,mid,nums);
        build(i*2+2,mid+1,h,nums);
        seg[i]=min(seg[i*2+1],seg[i*2+2]);
    }
    int  query(int i,int l,int h,int s,int e){
         if(l>=s and h<=e){
            // lie inside return all
            return seg[i];
        }
      if (h < s || l > e) 
        return 1e9;

       
        int mid=(l+h)/2;
        int left=query(i*2+1,l,mid,s,e);
        int right=query(i*2+2,mid+1,h,s,e);
        return min(left,right);
    }  
};



class Solution {
public:
    
    vector<int>start,end;
    vector<int>time;
    int n;
    vector<vector<int>>graph;
    vector<int>distance;
    void dfs(int i,int parent,int dis,int &tme){
        distance[i]=dis;
        start[i]=tme++;
        time.push_back(i);
        // cout<<"enter "<<i<<" \n";
        for(auto j:graph[i]){
            if(j!=parent and j!=i){
            dfs(j,i,dis+1,tme);
                tme++;
            time.push_back(i);     
            }
        }
        end[i]=tme++;
        time.push_back(i);
        return ;
    }
    int mod=1e9+7;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
//      using euler tour
        n=edges.size();
        start.resize(n+10);
        end.resize(n+10);
        graph.resize(n+2);
        distance.resize(n+2);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            }        
        int tme=0;
        dfs(1,0,0,tme);
        vector<int> ans;
        segmentTree st(time.size());
        vector<long>power={0,1};
        for(int i=0;i<=1e5;i++)power.push_back((power.back()*2)%mod);
        st.build(0,0,time.size()-1,time);
        for(auto i:queries){
            auto node=st.query(0,0,time.size()-1,min(start[i[0]],start[i[1]]),max(start[i[0]],start[i[1]]));
           
            ans.push_back(power[distance[i[0]]+distance[i[1]]-distance[node]*2]%mod);
            
        }
        return ans;
    }
};