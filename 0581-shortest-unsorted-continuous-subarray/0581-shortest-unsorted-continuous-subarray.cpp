class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        int c=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=nums[i])
            {
                c=i;
                break;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i]!=nums[i])
            {
                c=i-c+1;
                break;
            }
        }
        return c;
        
    }
};