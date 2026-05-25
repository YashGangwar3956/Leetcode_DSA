
function pathsWithMaxScore(board: string[]): number[] {
    const MOD = 1e9 + 7;
    const n = board.length;

    const grid: number[][] = [];
    const dp = new Map<string, [number, number]>();

    for (let i = 0; i < n; i++) {
        const row: number[] = [];

        for (let j = 0; j < board[i].length; j++) {
            const ch = board[i][j];

            if (ch === 'X') row.push(-1);
            else if (ch >= '1' && ch <= '9') row.push(Number(ch));
            else row.push(0);
        }

        grid.push(row);
    }

    const dfs = (i: number, j: number): [number, number] => {
        if (i >= n || j >= n || grid[i][j] === -1) {
            return [-Infinity, -Infinity];
        }

        if (i === n - 1 && j === n - 1) {
            return [0, 1];
        }

        const key = `${i},${j}`;

        if (dp.has(key)) {
            return dp.get(key)!;
        }

        const down = dfs(i + 1, j);
        const right = dfs(i, j + 1);
        const diagonal = dfs(i + 1, j + 1);

        const maxSum = Math.max(down[0], right[0], diagonal[0]);

        let totalPaths = 0;

        if (down[0] === maxSum) totalPaths = (totalPaths + down[1]) % MOD;
        if (right[0] === maxSum) totalPaths = (totalPaths + right[1]) % MOD;
        if (diagonal[0] === maxSum) totalPaths = (totalPaths + diagonal[1]) % MOD;

        const ans: [number, number] = [
            maxSum + grid[i][j],
            totalPaths
        ];

        dp.set(key, ans);

        return ans;
    };

    const [maxSum, paths] = dfs(0, 0);

    if (maxSum === -Infinity) return [0, 0];

    return [maxSum % MOD, paths % MOD];
}
