class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        m, n = len(mat), len(mat[0])
        def countArraysHaveSumLessOrEqual(targetSum, r, curSum, k):
            if curSum > targetSum: return 0
            if r == m: return 1  
            ans = 0
            for c in range(n):
                cnt = countArraysHaveSumLessOrEqual(targetSum, r + 1, curSum + mat[r][c], k - ans)
                if cnt == 0: break  
                ans += cnt
                if ans > k: break  
            return ans
        left, right, ans = m, m * 5000, -1
        while left <= right:
            mid = left + (right - left) // 2
            cnt = countArraysHaveSumLessOrEqual(mid, 0, 0, k)
            if cnt >= k:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans