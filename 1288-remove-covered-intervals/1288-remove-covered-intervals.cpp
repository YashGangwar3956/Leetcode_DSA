class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        int ct=0,l=-1,r=-1;
        for (auto i:intervals) {
            if(i[0]>l && i[1]>r){l=i[0];ct++;}
            r=max(r,i[1]);
        }
        return ct;
    }
};