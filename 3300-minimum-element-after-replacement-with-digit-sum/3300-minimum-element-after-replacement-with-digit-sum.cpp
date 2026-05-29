class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int a=nums[i],b=nums[i],sum=0;
            while(a){
                 sum+=a%10;
                 a=a/10;
            }
        sum=min(sum,b);
        ans=min(ans,sum);
        }
        return ans;
    }
};