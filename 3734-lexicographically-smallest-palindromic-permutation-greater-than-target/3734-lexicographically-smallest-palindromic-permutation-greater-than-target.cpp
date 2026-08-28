class Solution {
public:
    string ans;
    bool flag = false;
    vector<int>freq;
    void solve(string &target,int i,int j,vector<char>&v){
        if(i>j){
        string s1 = "";
        int k = 0;
        while(k<v.size()){
            s1 += v[k];
            k++;
        }
        if(s1>target){
            if(ans=="") ans = s1;
            else ans = min(ans,s1);
        }
            return;
        }

        for(int idx=0;idx<26;idx++){
            if(freq[idx]==0) continue;
            char ch = idx + 'a';

            if(!flag && (ch)<target[i]) continue;

            flag = (flag || (ch>target[i]));

            if(j-i+1>1){
                if(freq[idx]>=2){
                    freq[idx] -=2;
                    v[i] = ch;
                    v[j] = ch;
                    i++;
                    j--;
                    solve(target,i,j,v);
                    if(ans!="") return;
                    i--;
                    j++;
                    v[i] -= '*';
                    v[j] -= '*';
                    
                    freq[idx] += 2;
                }
            }
            else if(j-i+1==1 && freq[idx]==1){
                freq[idx] -=1;
                    v[i] = ch;
                    i++;
                    solve(target,i,j,v);
                    if(ans!="") return;
                    i--;
                    v[i] -= '*';
                    freq[idx] += 1;
            }
        }
        
    }
    string lexPalindromicPermutation(string s, string target) {

        freq.resize(26,0);
        ans = "";

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0) cnt++;
        }
        if(cnt>1) return "";
        vector<char>v(s.size(),'*');

        solve(target,0,s.size()-1,v);

        return ans;

    }
};