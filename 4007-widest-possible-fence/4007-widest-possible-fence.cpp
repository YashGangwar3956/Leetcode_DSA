class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        typedef long long ll ;
        unordered_map<ll,int> freq,mpp ;
        for ( auto it : planks ) freq[it]++ ;
        vector<pair<ll,int>> vec(freq.begin(), freq.end());
        for ( auto it : vec ) mpp[it.first] = it.second ;
        int n = vec.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i ; j < n ; j++ ) {
                ll value = vec[i].first + vec[j].first ;
                if ( i == j ) mpp[value] += vec[i].second / 2 ;
                else mpp[value] += min( vec[i].second , vec[j].second ) ;
                
             }
        } 
        int ans = 1 ;
        for ( auto it : mpp ) ans = max( ans , it.second ) ;
        return ans ;   
    }
};