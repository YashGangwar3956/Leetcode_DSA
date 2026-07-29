class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {

        int n = s.size();
        int l = 0, r = 1;

        if (n == 1 && s[0] == '1')
            return nums[0];

        vector<int> a(n, -1);

        long long ans = 0;

        if (s[0] == '1') {
            ans += nums[0];
            a[0] = 0;
            l = -1;
        }

        while (r < n) {

            if (s[r] == '1') {

                if (a[r - 1] == -1) {

                    if (nums[r - 1] >= nums[r]) {
                        ans += nums[r - 1];
                        a[r - 1] = 0;
                        l = r;
                    } else {
                        ans += nums[r];
                        a[r] = 0;
                        if (a[r - 1] == -1)
                            l = r - 1;
                    }

                } else {

                    if (l >= 0 && nums[r] <= nums[l]) {
                        ans += nums[l];
                        a[l] = 0;
                        l = r;
                    } else {
                        ans += nums[r];
                        a[r] = 0;
                    }
                }

            } else {
                l = r;
            }

            r++;
        }

        return ans;
    }
};