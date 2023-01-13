// Solution 1
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> secondary=new HashSet<int>();
        for (int i=0;i<nums.Length;i++)
            if (!secondary.Add(nums[i])) return true;            
        return false;  
    }
}
// Solution 2
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> distinct = new HashSet<int>();
        for (int i = 0; i < nums.Length; i++) {
            if (distinct.Contains(nums[i]))
                return true;
            distinct.Add(nums[i]);
        }
        return false;
    }
}
// Solution 3
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> secondary = new HashSet<int>();
        int counter = 0;
        bool ans = true;
        for (int i = 0; i < nums.Length; i++) {
                if (secondary.Add(nums[i]))
                    counter++;                                       
        }
        if(counter == nums.Length)
                return false;
        return true;
    }
}
