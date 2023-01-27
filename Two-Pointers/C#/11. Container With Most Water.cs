// https://leetcode.com/problems/container-with-most-water/

using System;

namespace MostWaterApp {
    public class Solution {
        public int MaxArea(int[] height) {
            int res = 0;
            int low = 0, high = height.Length - 1;
            while (low < high) {
                res = Math.Max(res, (high - low) * Math.Min(height[low], height[high]));
                if (height[low] < height[high]) low++;
                else high--;
            }
            return res;
        }
        static void Main(string[] args) {
            int[] height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
            int[] height2 = {1, 1};
            Solution oSolution = new Solution();
            int maxAreaVal1=oSolution.MaxArea(height1);
            Console.WriteLine(maxAreaVal1);
            int maxAreaVal2 = oSolution.MaxArea(height2);
            Console.WriteLine(maxAreaVal2);
            Console.ReadKey();
        }
    }
}
