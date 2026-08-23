class Solution {
public:
    bool isPalindromic(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            for (int bit = 7; bit >= 0; --bit) {
                int leftBit  = (s[l] >> bit) & 1;
                int rightBit = (s[r] >> (7 - bit)) & 1;

                if (leftBit != rightBit)
                    return false;
            }

            l++;
            r--;
        }

        return true;
    }
};