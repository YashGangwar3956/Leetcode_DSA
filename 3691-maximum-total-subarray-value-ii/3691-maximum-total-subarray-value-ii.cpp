class Solution {
public:
    set<pair<int, int>> vis;
array<long long, 5> computeVal(int i, int j, int l, int r, vector<int>& nums, vector<int>& ids) { 
    if (!vis.insert({i, j}).second)
        return {};        
    while (ids[l] <= i || ids[l] >= j)
        ++l;
    while (ids[r] <= i || ids[r] >= j)
        --r;
    return {nums[ids[r]] - nums[ids[l]], i, j, l, r};
}
long long maxTotalValue(vector<int>& nums, int k) {
    vector<int> ids(nums.size());
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](int i, int j){ 
        return nums[i] == nums[j] ? i < j : nums[i] < nums[j]; 
    });
    long long res = 0;
    priority_queue<array<long long, 5>> pq;
    pq.push(computeVal(-1, nums.size(), 0, nums.size() - 1, nums, ids));
    while (!pq.empty() && pq.top()[0] && k > 0) {
        auto [val, i, j, l, r] = pq.top(); pq.pop();
        long long ni = min(ids[r], ids[l]), nj = max(ids[r], ids[l]);
        long long cnt = min((ni - i) * (j - nj), (long long)k);
        k -= cnt;
        res += val * cnt;
        pq.push(computeVal(ni, j, l, r, nums, ids));
        pq.push(computeVal(i, nj, l, r, nums, ids));
    }
    return res;
}
};