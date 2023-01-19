// Solution 1
public class Solution {
    public int DifferenceOfSum(int[] nums) {
        int elementSum = 0, digitSum = 0;
        for(int i = 0;i<nums.Length;i++) {
            elementSum += nums[i];
            int[] charDig = nums[i].ToString().Select(o=> Convert.ToInt32(o) - 48 ).ToArray();
            if (charDig.Length>1) for(int j = 0; j<charDig.Length;j++) digitSum += charDig[j];
            else digitSum += nums[i];
        }
        return Math.Abs(digitSum - elementSum);
    }
}

// Solution 2

public class Solution {
    public int DifferenceOfSum(int[] nums) {
        int elementSum=0,digitSum=0;
        for (int i =0; i<nums.Length; i++) {
            int num = nums[i];
            elementSum += num;
            while(num>0) {
                digitSum += num%10;
                num /= 10;
            }
        }
        return Math.Abs(digitSum - elementSum);
    }
}
