class Solution {
public:
        bool canReach(vector<int>& s, vector<int>& t) {
        return (s[0] + s[1] + t[0] + t[1]) % 2 == 0;
    }
};