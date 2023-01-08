using System;

namespace app3SumClosest {
    public class Solution {
        public int ThreeSumClosest(int[] nums, int target) {
            if (nums.Length < 3) return 0;
            int closest = nums[0] + nums[1] + nums[2];
            Array.Sort(nums);
            for (int first = 0; first < nums.Length - 2; ++first) {
                if (first > 0 && nums[first] == nums[first - 1]) continue;
                int second = first + 1, third = nums.Length - 1;
                while (second < third) {
                    int curSum = nums[first] + nums[second] + nums[third];
                    if (curSum == target) return curSum;
                    if (Math.Abs(target - curSum) < Math.Abs(target - closest)) closest = curSum;
                    if (curSum > target) --third;
                    else ++second;
                }
            }
            return closest;
        }
        static void Main(string[] args) {
            int[] nums = { -1, 2, 1, -4 };
            int target = 1;
            Solution oSolution=new Solution();
            int res=oSolution.ThreeSumClosest(nums, target);
        }
    }
}
