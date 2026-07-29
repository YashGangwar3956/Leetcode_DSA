class Solution {
public:
		int MOD = 1e9+7;
		using ll = long long;
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) 
    {	
    		ll n = value.size();
    		ll max_moves = m;
    		auto max_select = [&](ll x){
    			ll count = 0;
    			for (int i = 0; i < n; i++){
    				if (value[i] < x) continue;
    				count += (value[i]-x)/decay[i] + 1;
    				if (count >= max_moves) return count;
    			}
    			return count;
    		};
    		ll low = 1, high = 1e9;
    		// for (auto v : value) high = max(high,(ll)v);
    		while (low <= high) {
    			ll mid = low + (high-low)/2;
    			if (max_select(mid) >= max_moves) low = mid+1;
    			else high = mid-1;
    		}
    		ll lower_cap = high,ANS = 0, selected = 0;
    		for (int i = 0; i < n; i++) {
    			if (value[i] <= lower_cap) continue;
    			ll count = (value[i]-lower_cap-1)/decay[i] + 1;
    			selected += count;
    			// sum = n/2(2a + (n-1)d)
    			ll sum = ((count)*(2*value[i] - (count-1)*decay[i]))/2;
    			ANS += sum;
    			ANS %= MOD;
    		}
    		// fill rest with lower_cap/ subtract the rest 
    		ll sum = (max_moves - selected)*lower_cap;
    		ANS = (ANS + sum)%MOD;
    		return ANS;
    		
    }
};


