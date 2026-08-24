class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
         partial_sum(begin(A), end(A), begin(A));
        return accumulate(next(rbegin(A)), prev(rend(A)), A.back(), [](int memo, int cur) { return max(memo, cur - memo); });
    }
};