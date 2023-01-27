// https://leetcode.com/problems/3sum/

using System;
using System.Collections.Generic;
using System.Linq;

namespace MostWaterApp {
    public class Solution {
        public IList<IList<int>> ThreeSum(int[] nums) {
            var reslist = new List<IList<int>>();
            Array.Sort(nums);
            var pre = 0;
            for (var i = nums.Length - 1; i > 1; i--) {
                if (i != nums.Length - 1 && nums[i] == pre) continue;
                var remain = 0 - nums[i];
                pre = nums[i];
                var prev = 0;
                for (var j = i - 1; j > 0; j--) {
                    if (j != i - 1 && nums[j] == prev) continue;
                    var last = remain - nums[j];
                    prev = nums[j];
                    var exist = Array.BinarySearch<int>(nums, 0, j, last);
                    if (exist >= 0) reslist.Add(new List<int>() { nums[i], nums[j], last });
                }
            }
            return reslist;
        }
    static void Main(string[] args) {
            int[] nums1 = { -1, 0, 1, 2, -1, -4 };
            int[] nums2 = { 0, 1, 1 };
            int[] nums3 = { 0, 0,0 };
            Solution oSolution = new Solution();
            IList<IList<int>> ThreeSumVal1 = oSolution.ThreeSum(nums1);
            Console.WriteLine("First Result\n");
            foreach (var obj in ThreeSumVal1.SelectMany(l => l.Select(o => o))) {
                Console.WriteLine(obj);
            }
            IList<IList<int>> ThreeSumVal2 = oSolution.ThreeSum(nums2);
            Console.WriteLine("Second Result \n");
            foreach (var obj in ThreeSumVal2.SelectMany(l => l.Select(o => o))) {
                Console.WriteLine(obj);
            }
            IList<IList<int>> ThreeSumVal3 = oSolution.ThreeSum(nums3);
            Console.WriteLine("Third Result\n");
            foreach (var sublist in ThreeSumVal3) {
                foreach (var obj in sublist) {
                    Console.WriteLine(obj);
                }
            }
            Console.ReadKey();
        }
    }
}
