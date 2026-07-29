class Solution {
public:
    vector<int>dp;
    int solve(int i, string &source, string &target, vector<vector<string>>& rules,
                vector<int>& costs) {
        if(i==source.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int nottake = INT_MAX;
        if (source[i] == target[i]) {
            nottake = solve(i + 1, source, target, rules, costs);
        }
        int take = INT_MAX;
        for (int t = 0; t < rules.size(); t++) {
            string pattern = rules[t][0];
            string repl = rules[t][1];
            bool flag = true;
            int ttt = i;
            int cnt=0;
            int sze=pattern.size();
            if(i+sze>source.size()) continue; 
            for (int tt = 0; tt <sze; tt++) {
                if(!(pattern[tt]=='*' || pattern[tt]==source[ttt])){
                    flag=false;
                    break;
                }
                if(repl[tt]!=target[ttt]){
                    flag=false;
                    break;
                }
                if(pattern[tt]=='*'){
                    cnt++;
                }
                ttt++;
            }
            if(flag){
                int val=solve(i+sze, source, target, rules, costs);
                if(val!=INT_MAX) take=min(take,costs[t]+cnt+val);
            }
        }
        return dp[i]=min(take,nottake);
    }
    int minCost(string source, string target, vector<vector<string>>& rules,
                vector<int>& costs) {
                    int n=source.size();
                    dp.resize(n+1,-1);
                    int ans=solve(0, source, target, rules, costs);
                    return (ans==INT_MAX)?-1:ans;
                }
};