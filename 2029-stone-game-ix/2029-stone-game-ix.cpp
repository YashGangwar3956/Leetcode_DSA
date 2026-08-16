class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>hash(3,0);
        for(int i=0;i<stones.size();i++)
        hash[stones[i]%3]++;
         int a=min(hash[1],hash[2]);
         int b=max(hash[1],hash[2]);
        if(a==0&&b>2) return hash[0]%2==1;
        else if(a==0)return false;
        return hash[0]%2==0 or b>a+2;
    }
};