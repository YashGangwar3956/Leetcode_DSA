class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string news='1'+s+'1';
        int c1=0;
        for(auto i:s){
            if(i=='1'){
                c1++;
            }
        }
        int i=1,ans=c1;
        while(i<news.size()-1){
            if(news[i]=='1'){
                int k=i;
                while(k<news.size() && news[k]=='1'){
                    k++;
                }
                if(k<news.size()-1 && news[i-1]=='0' && news[k]=='0'){
                    int c2=0,c3=0,l=i-1;
                    while(l>=0 && news[l]=='0'){
                        c2++;
                        l--;
                    }
                    l=k;
                    while(l<news.size() && news[l]=='0'){
                        c3++;
                        l++;
                    }
                    ans=max(ans,c1+c2+c3);
                }
                i=k;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};