public class Solution {
    public int MaxArea(int[] height) {
        int res=0, low=0, high=height.Length-1;
        while (low<high) {
            res = Math.Max(res,(high-low)*Math.Min(height[low],height[high]));
            if (height[low]<height[high]) low++;
            else high--;
        }
        return res;
    }
}
