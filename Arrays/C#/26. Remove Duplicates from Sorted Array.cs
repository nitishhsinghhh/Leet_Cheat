// Solution 1
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        HashSet<int> secondary = new HashSet<int>();
        int res = 0;
        for (int i = 0; i < nums.Length; i++)
            if (secondary.Add(nums[i]))
                nums[res++] = nums[i];     
        return res;
    }
}
// Solution 2
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        HashSet<int> secondary = new HashSet<int>();
        Dictionary<int, int> uniqueValues = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) 
            if (secondary.Add(nums[i])) 
                uniqueValues.Add(i + 1, nums[i]);                 
        int [] res = uniqueValues.Values.ToArray();
        for (int i = 0; i < nums.Length; i++)
            if (i < res.Length)
                nums[i] = res[i];
        return res.Length;
    }
}
