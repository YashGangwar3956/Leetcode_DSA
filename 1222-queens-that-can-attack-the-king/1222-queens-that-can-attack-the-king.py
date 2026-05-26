class Solution:
    def queensAttacktheKing(self, queens, king, DIRS=[(0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1)]):
        q = {(r,c) for r,c in queens}
        return list(filter(None, (next(([king[0]+dr*i, king[1]+dc*i] for i in range(8) if (king[0]+dr*i, king[1]+dc*i) in q), None) for dr, dc in DIRS)))