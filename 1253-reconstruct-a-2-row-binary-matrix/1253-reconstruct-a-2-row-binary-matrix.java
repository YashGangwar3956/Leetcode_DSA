class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int n = colsum.length;
        List<List<Integer>> result = new ArrayList<>();
        Integer upperRow[] = new Integer[n];
        Integer lowerRow[] = new Integer[n];
        Arrays.fill(upperRow, 0);
        Arrays.fill(lowerRow, 0);
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                upperRow[i] = 1;
                lowerRow[i] = 1;
                upper--;
                lower--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    upperRow[i] = 1;
                    upper--;
                } else if (lower > 0) {
                    lowerRow[i] = 1;
                    lower--;
                } else {
                    return result;
                }
            }
        }
        if (upper != 0 || lower != 0) {
            return result;
        }
        result.add(Arrays.asList(upperRow));
        result.add(Arrays.asList(lowerRow));
        return result;
    }
}