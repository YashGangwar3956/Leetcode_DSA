class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n=units.size();
        int m=units[0].size();
        long long ans=0;
        int gminx=INT_MAX;    // global mininum per device
        int gsminx=INT_MAX;   // global second minimum per device
        for(int i=0;i<n;i++){
            int minx=INT_MAX;    // minimum per device
            int sminx=INT_MAX;   // second minimum per device
            for(int j=0;j<m;j++){
                if(units[i][j]<=minx){
                    sminx=minx;
                    minx=units[i][j];
                }else if(units[i][j]<sminx){
                    sminx=units[i][j];
                }
            }
            gminx=min(gminx,minx);
            gsminx=min(gsminx,sminx);
            if(sminx==INT_MAX){
                ans+=minx;
            }else{
                ans+=sminx;
            }
        }
        if(gsminx==INT_MAX){
            return ans;
        }
        return ans-gsminx+gminx;
    }
};