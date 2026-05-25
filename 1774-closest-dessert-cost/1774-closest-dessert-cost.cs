
public class Solution {
    int target;

    int Closest(int a, int b) {
        if (a == 0)
            return b;

        if (b == 0)
            return a;

        if (Math.Abs(target - a) == Math.Abs(target - b))
            return a < b ? a : b;

        return Math.Abs(target - a) < Math.Abs(target - b) ? a : b;
    }

    int Dfs(int[] top, int i, int sum) {
        if (i >= top.Length)
            return sum;

        int a = Dfs(top, i + 1, sum + top[i]);
        int b = Dfs(top, i + 1, sum + (top[i] * 2));
        int c = Dfs(top, i + 1, sum);

        sum = Closest(a, Closest(b, c));

        return sum;
    }

    public int ClosestCost(int[] baseCosts, int[] toppingCosts, int target) {
        this.target = target;

        int ans = 0;

        for (int i = 0; i < baseCosts.Length; i++) {
            ans = Closest(Dfs(toppingCosts, 0, baseCosts[i]), ans);
        }

        return ans;
    }
}
