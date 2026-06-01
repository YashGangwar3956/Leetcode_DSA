class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        if(n==1)return cost[0];
        if(n==2)return cost[0]+cost[1];
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0;
        for(auto i:cost){
            sum+=i;
        }
        int free=0;
        for(int i=2;i<n;i+=3){
            free+=cost[i];
        }
        return sum-free;
    }
};