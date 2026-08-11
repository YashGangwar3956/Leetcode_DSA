class Solution {
public:
    int missingInteger(vector<int>& nums) {
         int length =nums.size(),i,sum=nums[0];
        for(i=1;i<length;i++){
            if(nums[i]!=nums[i-1]+1)break;
            sum+=nums[i];
        }
        sort(nums.begin()+i,nums.end());
        for(i=0;i<length;i++){
            if(sum>nums[i])continue;
            if(sum==nums[i])sum++;
            else break;
        }
        return sum;
    
    }
};