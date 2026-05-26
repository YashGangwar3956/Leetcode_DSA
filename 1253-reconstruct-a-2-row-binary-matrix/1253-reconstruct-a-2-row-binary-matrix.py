class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        n = len(colsum)
        upper_list = [0 for _ in range(n)]
        lower_list = [0 for _ in range(n)]
        
        for i, v in enumerate(colsum):
            if v == 1:
                if upper > lower:
                    upper_list[i] = 1
                    upper -= 1
                else:    
                    lower_list[i] = 1
                    lower -= 1
            elif v == 2:        
                upper_list[i] = lower_list[i] = 1
                upper, lower = upper - 1, lower - 1
                
        return [upper_list, lower_list] if upper == lower == 0 else []