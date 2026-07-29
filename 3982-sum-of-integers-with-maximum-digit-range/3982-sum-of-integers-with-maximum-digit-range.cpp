class Solution {
public:
    int maxDigitRange(vector<int>& nums) 
    {
        int n=nums.size(),maxi=0,res=0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            int ans=findDiffForSmallestAndLargest(nums[i]);
            maxi=max(maxi,ans);
            mp[ans].push_back(nums[i]);
        }
        for(auto it:mp[maxi])
        {
            res+=it;
        }
        return res;
    }
    int findDiffForSmallestAndLargest(int n)
    {
        int maxi=INT_MIN,mini=INT_MAX;
        while(n)
        {
            int rem=n%10;
            maxi=max(maxi,rem);
            mini=min(mini,rem);
            n/=10;
        }
        return maxi-mini;
    }
};