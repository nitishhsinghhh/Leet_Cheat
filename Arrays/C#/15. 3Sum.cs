using System;
using System.Collections.Generic;

namespace app3Sum {
    public class Solution {
        public IList<IList<int>> ThreeSum(int[] nums) {
            var reslist = new List<IList<int>>();
            Array.Sort(nums);
            var pre = 0;
            for (var i = nums.Length - 1; i > 1; i--) {
                if (i!=nums.Length-1 && nums[i]==pre) continue;
                var remain=0-nums[i];
                pre = nums[i];
                var prev = 0;
                for (var j=i-1;j>0;j--) {
                    if (j!=i-1 && nums[j]==prev) continue;
                    var last=remain-nums[j];
                    prev=nums[j];
                    var exist=Array.BinarySearch<int>(nums,0,j,last);
                    if (exist>=0) reslist.Add(new List<int>() {nums[i],nums[j],last});
                }
            }
            return reslist;
        }
        static void Main(string[] args) {
            int[] nums={-1,0,1,2,-1,-4};
            Solution oSolution=new Solution();
            var reslist=oSolution.ThreeSum(nums);
        }
    }
}
