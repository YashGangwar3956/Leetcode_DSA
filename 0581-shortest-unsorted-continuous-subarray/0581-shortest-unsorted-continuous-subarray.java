class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n=nums.length;
        int []sorted=nums.clone();
        Arrays.sort(sorted);
        int start=0;
        int end=n-1;
        while(start<n && sorted[start]==nums[start])
        start++;
        while(end>start && sorted[end]==nums[end])
        end--;
        return end-start+1;
    }
}