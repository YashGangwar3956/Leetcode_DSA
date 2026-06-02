class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
         int res = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for (int i = 0; i < n; ++i) {
            int a = landStartTime[i];
            int d = landDuration[i]; 
            for (int j = 0; j < m; ++j) {
                int b = waterStartTime[j];
                int e = waterDuration[j];  
                int landEnd = a + d;
                int startWater = max(landEnd, b); 
                int finish1 = startWater + e;
                int waterEnd = b + e;
                int startLand = max(waterEnd, a); 
                int finish2 = startLand + d;
                res = min({res, finish1, finish2});
            }
        }
        return res;
    }
};