import heapq
class Solution(object):
    def cutOffTree(self, forest):
        heap = []
        for row in range(len(forest)):
            for col in range(len(forest[0])):
                if forest[row][col] > 1:
                    heapq.heappush(heap, (forest[row][col],row,col))
        
        steps = 0
        row, col = 0, 0
        while heap:    
            height, x, y = heapq.heappop(heap)
            val = self.calculateSteps(forest, row, col, x, y)    
            if val == -1:
                return val
            forest[x][y] = 1
            row, col = x, y
            steps += val
            
        return steps    

    def calculateSteps(self, matrix, s_x, s_y, d_x, d_y):
        
        direction = [[0,1], [0,-1], [1,0], [-1,0]]
        distance = 0
        queue = [(s_x,s_y)]
        visited = {(s_x,s_y)}
        
        while queue:            
            level_size = len(queue)
            for _ in range(level_size):
                nei_x, nei_y = queue.pop(0)

                if nei_x == d_x and nei_y == d_y:
                    return distance

                for direc in direction:
                    scale_x = nei_x + direc[0]
                    scale_y = nei_y + direc[1]
                    if scale_x >= 0 and scale_x < len(matrix) and scale_y >= 0 and scale_y < len(matrix[0]) and matrix[scale_x][scale_y] > 0 and (scale_x,scale_y) not in visited:
                        queue.append((scale_x,scale_y))
                        visited.add((scale_x,scale_y))

            distance += 1
        return -1