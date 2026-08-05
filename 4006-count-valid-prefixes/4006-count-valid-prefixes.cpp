class Solution {
public:
       int countValidPrefixes(string s) {
        int res = 0, diff = 0;
        for (char c : s) {
            diff += c == '1' ? 1 : -1;
            res += abs(diff) <= 1;
        }
        return res;
    }
};