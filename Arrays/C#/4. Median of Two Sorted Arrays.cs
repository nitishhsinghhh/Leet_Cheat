// 1. Solution #1
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {		
        int[] ans = nums1.Concat(nums2).OrderBy(x => x).ToArray();
		int n = ans.Length;
        decimal medianSorted;
        if (n % 2 !=0) medianSorted = ans[n / 2];
        else medianSorted = Decimal.Divide((ans[n / 2] + ans[(n - 1) / 2]), 2);
        return Convert.ToDouble(medianSorted);
    }
}
// 2. Solution #2
//By combining both cases into one to get the result.
public class Solution {
     public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1=nums1.Length;
        int len2=nums2.Length;
        if (len1<len2) return FindMedianSortedArrays(nums2,nums1);
		int low=0, high=len2*2;
        while (low<=high) {
			int mid2=(low+high)/2;
            int mid1=len1+len2-mid2;
			double L1=(mid1==0)?Int32.MinValue:nums1[(mid1-1)/2];
            double L2=(mid2==0)?Int32.MinValue:nums2[(mid2-1)/2];
            double R1=(mid1==len1*2)?Int32.MaxValue:nums1[(mid1)/2];
            double R2=(mid2==len2*2)?Int32.MaxValue:nums2[(mid2)/2];
            if (L1>R2) low=mid2 + 1;
            else if(L2>R1) high=mid2-1;
            else
				return (Math.Max(L1,L2)+Math.Min(R1,R2))/2;
      }
      return -1;
     }
}
