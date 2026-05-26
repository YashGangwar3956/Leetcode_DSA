class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
                --upper; --lower;
            }
        }
        if (upper < 0 || lower < 0) return {};
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1) {
                if (upper) {
                    ++res[0][i];
                    --upper;
                } 
                else if (lower) {
                    ++res[1][i];
                    --lower;
                } 
                else return {};
            }
        }
        if (upper != 0 || lower != 0) return {};
        return res;
    }
};