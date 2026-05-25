class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        sorted_arr = list(sorted(arr))
        n = len(arr)
        
        @lru_cache(None)
        def dp(left):
            if left == n:
                return 0
            
            count = 0
            left1_set = collections.defaultdict(int)
            left2_set = collections.defaultdict(int)
            count = 0
            for i in range(left, n):
                left1_set[arr[i]] += 1
                left2_set[sorted_arr[i]] += 1
                if left1_set == left2_set:
                    count = 1 + dp(i+1)
                    break
                    
            return count
        
        return dp(0)