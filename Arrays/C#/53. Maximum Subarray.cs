public class Solution {
   public int MaxSubArray(int[] nums){
        int globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.Length; ind++) {
            currMaxSum = Math.Max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = Math.Max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }
}
