class Solution {
    public int maximumRows(int[][] matrix, int numSelect) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] rowMasks = new int[rows];
        for (int i = 0; i < rows; i++) {
            int mask = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    mask |= (1 << j);
                }
            }
            rowMasks[i] = mask;
        }

        int maxCovered = 0;
        int totalCombinations = 1 << cols;
        for (int mask = 0; mask < totalCombinations; mask++) {
            if (Integer.bitCount(mask) == numSelect) {
                int currentCovered = 0;
                for (int rowMask : rowMasks) {
                    if ((rowMask & mask) == rowMask) {
                        currentCovered++;
                    }
                }
                maxCovered = Math.max(maxCovered, currentCovered);
            }
        }
        return maxCovered;
    }
}