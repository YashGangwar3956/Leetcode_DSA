class Solution {
    public int minElement(int[] nums) {
        
        for(int i=0; i<nums.length; i++){
            int sum=0;
            while(nums[i] > 0){
                int temp = nums[i];
                temp %= 10;
                sum += temp;
                nums[i] /= 10;
            }
            nums[i] = sum;
        }

        Arrays.sort(nums);
        return nums[0];
    }
}