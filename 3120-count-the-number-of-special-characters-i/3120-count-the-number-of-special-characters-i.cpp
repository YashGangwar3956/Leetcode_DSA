class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(auto i:word)mp[i]++;
        string s="";
        for(auto i:mp){
            s+=i.first;
        }
       transform(s.begin(),s.end(),s.begin(),::tolower);
        mp.clear();
       for(auto i:s){
           mp[i]++;
       }
        int ct=0;
        for(auto i:mp){
            if(i.second>1)ct++;
        }
        return ct;
    }
};