class Solution {
    public static int MOD = (int)1e9 + 7;
    long[] bit1, bit2;
    public int sumCounts(int[] nums) {
        int max = 0;
        for(int num : nums) max = Math.max(max, num);
        int[] numToIndex = new int[max+1];
        Arrays.fill(numToIndex, -1);
        int n = nums.length;
        int suffixSq = 0, res = 0;
        bit1 = new long[n+1];
        bit2 = new long[n+1];
        for(int i = 0; i < n; i++) {
            int lastIdx = numToIndex[nums[i]];
            suffixSq = (int)((suffixSq + 2*(query(lastIdx+1, i-1)) + i-lastIdx) % MOD);
            update(lastIdx+1, i);
            res = (res + suffixSq) % MOD;
            numToIndex[nums[i]] = i;
        }
        return res;
    }

    private long query(int l, int r) {
        return query(r) - query(l-1);
    }

    private long query(int x) {
        return x*query(x, bit1) - query(x, bit2);
    }

    private void update(int l, int r) {
        update(l, 1, bit1);
        update(r+1, -1, bit1);
        update(l, l-1, bit2);
        update(r+1, -r, bit2);
    }

    private void update(int idx, long val, long[] bit) {
        for(int i = idx+1; i < bit.length; i += (i & -i)) {
            bit[i] += val;
        }
    }

    private long query(int idx, long[] bit) {
        long res = 0;
        for(int i = idx+1; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }
}