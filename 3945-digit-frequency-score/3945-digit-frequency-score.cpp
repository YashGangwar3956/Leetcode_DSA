class Solution {
public:
    int digitFrequencyScore(int n) {
        int f[10] = {0};
        while(n) {
            f[n % 10]++;
            n /= 10;
        }
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            ans += i * f[i];
        }
        return ans;
    }
};