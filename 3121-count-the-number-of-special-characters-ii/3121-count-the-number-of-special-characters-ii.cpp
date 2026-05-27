class Solution {
public:
    int numberOfSpecialChars(string b){
    map<char, int>c;
    map<char,int>d;
    for (int e=0;e<b.size();e++) {
        char f=tolower(b[e]);
        if(islower(b[e]))c[f]=e;
        else{
            if(d.find(f)==d.end())d[f]=e;
            }
        }
        int g=0;
        for(auto h:c){
            if(d.find(h.first)!=d.end() && h.second<d[h.first])
               g++;
            }
            return g;
    }
};