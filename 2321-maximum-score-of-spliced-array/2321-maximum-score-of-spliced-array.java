
class Solution {
    public int maximumsSplicedArray(int[] nums1, int[] nums2) {
        int[] kd = new int[2];
        int[] res = new int[2];
        int[] sum = new int[2];

        for (int i = 0; i < nums1.length; i++) {
            kd[0] = Math.max(nums2[i] - nums1[i], kd[0] + nums2[i] - nums1[i]);
            res[0] = Math.max(res[0], kd[0]);

            kd[1] = Math.max(nums1[i] - nums2[i], kd[1] + nums1[i] - nums2[i]);
            res[1] = Math.max(res[1], kd[1]);

            sum[0] += nums1[i];
            sum[1] += nums2[i];
        }

        return Math.max(sum[0] + res[0], sum[1] + res[1]);
    }
}
