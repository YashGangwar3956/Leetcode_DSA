class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
       vector<int>pref;
       pref.push_back(0);
       int sum=0;
        for(int i=0;i<n;i++){
            sum+=gain[i];
            pref.push_back(sum);
        }
        int maxi=INT_MIN;
        for(auto i:pref){
            maxi=max(maxi,i);
        }
        return maxi;
    }
};