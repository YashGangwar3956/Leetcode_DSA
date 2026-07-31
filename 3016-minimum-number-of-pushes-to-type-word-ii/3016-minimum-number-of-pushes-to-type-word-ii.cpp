class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto i:word){
            mp[i]++;
        }
        vector<int>v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=(v[i])*(int)(ceil((float)(i+1)/8));
        }
        return ans;
    }
};