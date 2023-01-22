/*
4. Median of Two Sorted Arrays

  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
  The overall run time complexity should be O(log (m+n)).

  Example 1:
  Input: nums1 = [1,3], nums2 = [2]
  Output: 2.00000
  Explanation: merged array = [1,2,3] and median is 2.

  Example 2:
  Input: nums1 = [1,2], nums2 = [3,4]
  Output: 2.50000
  Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
  Constraints:
  nums1.length == m
  nums2.length == n
  0 <= m <= 1000
  0 <= n <= 1000
  1 <= m + n <= 2000
  -10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 < len2) swap(nums2, nums1);
		int low = 0, high = len2 * 2;
		while (low <= high) {
			int mid2 = (low + high) / 2;
			int mid1 = len1 + len2 - mid2;
			double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
			double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
			double R1 = (mid1 == len1 * 2) ? INT_MAX : nums1[(mid1) / 2];
			double R2 = (mid2 == len2 * 2) ? INT_MAX : nums2[(mid2) / 2];
			if (L1 > R2)low = mid2 + 1;
			else if (L2 > R1) high = mid2 - 1;
			else return (max(L1, L2) + min(R1, R2)) / 2;
		}
		return -1;
	}
};

int main() {
	vector<int> nums1{ 1, 2 };
	vector<int> nums2{ 3, 4 };
	Solution oSolution;
	double value = oSolution.findMedianSortedArrays(nums1, nums2);
    std::cout << "Success!\n";
}

/*
  
  ==========================================================================================================================================================================
  
  The steps for finding the median differ depending on whether you have an odd or an even number of data points. If there are two numbers in the middle of a dataset, there mean is the median.
  
  The first solution comes to mind is to consider two cases
  A. Odd Length Array and B. Even length Array
  
  A. Median with an odd-numbered dataset
  weeklyPay = [350 800 220 500 130]
  As per the problem statement data is sorted, else data needs to be sorted
  sorted weeklyPay = [130 220 350 500 800]  
  The middle position is (n+1)/2! So the median pay is 350 per day.
  
  B. Median with an even-numbered dataset
    weeklyPay = [350,800,220,500,130,1150]
    sorted weeklyPay = [130,220,350,500,800,1150]    
    The middle position is n/2 and (n+1)/2! So the median pay is 350 per week.

  Another way of seeing the solution is we make a cut through 350   
  1. [130 220 (350/350) 500 800]
  Now we have two sub arrays LA1[130 220 350], RA1[350 500 800]
  Median is (350+350)/2 = 350
  
  2. [130 220 350 / 500 800 1150] 
   Now we have two sub arrays LA2[130 220 350] RA2[500 800 1150]
   Median is (350+500)/2 = 425

  Let's say LL represent last element of LA array and RF is the first element of RA element.

  Let's see the LL and RF with respect to length of array
  Length of Array         Index LL          Index RF
      1                      0                  0
      2                      0                  1
      3                      1                  1
      4                      1                  2
      5                      2                  2
      6                      2                  3
      7                      3                  3
      8                      3                  4
      9                      4                  4
     10                      4                  5
     11                      5                  5
     
  "If we cut the sorted array to two halves of EQUAL LENGTHS, then
  median is the AVERAGE of max(lower_half) and min(upper_half), i.e. the
  two numbers immediately next to the cut." 
  
  Now consider for both cases, odd and even nunber of elements for the two array situations.
  Let us add an imaginary positions #'s in between numbers and treat them as postions.
  
  [6 9 13 18] ~>     [# 6 # 9 # 13 # 18 #] 
  position index      0 1 2 3 4 5  6 7  8 
  For N equals to 4 there are 9 positions.
  
  [6 9 11 13 18] ~>     [# 6 # 9 # 11 # 13 # 18 #] 
  position index         0 1 2 3 4 5  6  7 8 9  10
  For N equals to 5 there are 11 positions.
  
  So there are exactly 2*N+1 positions regardless of length N. So index of LL would always be (N-1)/2
  and index of RF would be N/2.
  Thus median of both would be (LL+RF)/2 = (A[N-1]/2 + A[N/2])/2
  
  ==========================================================================================================================================================================
  
  Two array case:
  
  A1: [# 1 # 2 # 3 # 4 # 5 #]    (N1 = 5, N1_positions = 11)

  A2: [# 1 # 1 # 1 # 1 #]     (N2 = 4, N2_positions = 9)
 
  Now similar to the one array problem, we need to find the two split arrays such that:
  "Any number in the two left halves" <= "Any number in the two right halves".

  Observations:
  A. There are exaclty (2N1 + 1) + (2N2 + 1), 2(N1 + N2 + 1) postions altogether. There are (N1 + N2)
  positions on each side of the cut and two positions on the cut.
  B. Therefore, when we cut at position C2 = K in A2, then the cut position in A1 must be C1 = N1 + N2 - k. For instance, if C2 = 2, then we must have C1 = 4 + 5 - C2 = 7.
  [# 1 # 2 # 3 # (4/4) # 5 #]    
  [# 1 / 1 # 1 # 1 #]   
  
  ==========================================================================================================================================================================
  Lets's deep dive on this tricky part (Observation B)

  N is size of the array. No. of position is 2N + 1.
  Cut will take one position and making the remaining position to be 2N.
  And we need to have equal element of both size to have a median cut.
  Which mean each part of the element should have N position.

  [# 1 # (2/2) # 3 # ]
   0 1 2 3     4 5 6
  N = 3, we have N * 2 + 1 = 7 position. We need to have N position on both size which is 3.
  We cut at 3. Left part is [#, 1, #] and right is [#, 3, #].

  [# 1 # 2 / 4 # ]
   0 1 2 3 4 5 6 
  [# 3 # (5/5) # 6 # 7 # ]
   0 1 2  3    4 5 6 7 8
  On cases with 2 array. We need to have 2 cut and total position is 2N1 + 2N2 + 2.
  2 cut will take out 2 position element. Total remaining position is 2N1 + 2N2 after we cut on both array.
  This mean each part should have (2N1 + 2N2) / 2 = N1 + N2.
  And it we cut at C1, there will be C1 amount of position on the left part. (C1 is 0-based)).
  And we can then know we need C2 = N1 + N2 - C1 from the left part of A2.
  Then we know we need to place the cut on C2. (C2 is 0-based)).

  We cut A1 at C1 = 4, left part is [#, 1, #, 2]. We need C2 = 3 + 4 - C1 = 3 more element.
  So we cut at C2 at 3.
  
  ==========================================================================================================================================================================
  
  C. Now after the cuts made, we have two LL's and two RF's.
  
  LL1 = A1[(C1-1)/2]; RF1 = A1[C1/2];
  LL2 = A2[(C2-1)/2]; RF2 = A2[C2/2];

  D. No to decide the right cut, we need to these conditions to be followed.
  LL1 <= RF1 && LL1 <= RF2 && LL2 <= RF1 && LL2 <= RF2
  
  As both array are sorted then we know these two conditions are always true.
  LL1 <= RF1 and LL2 <= RF2
  
  Only this case needs to be taken care of
  LL1 <= RF2 and LL2 <= RF1
  
  Now in sorted array we can use simple binary search to find the results. 
  
  If we have L1 > R2, it means there are too many large numbers on the left half of A1, then we must move C1 to the left (i.e. move C2 to the right); 
  If L2 > R1, then there are too many large numbers on the left half of A2, and we must move C2 to the left.
  Otherwise, this cut is the right one. 
  After we find the cut, the medium can be computed as (max(L1, L2) + min(R1, R2)) / 2;
  
  Notes:
  A. As C1 and C2 are mutually determined from each other, we can just move one and other can be found.
  Howeverto get run-time complexity of O(log(min(N1,N2))) and more practical to move C2; or the one on 
  the shorter array.
  B. The only edge case which a cut falls is 0th (first) or the 2Nth(last). To solve this problem, we 
  can imagine that both A1 and A2 actually have two extra elements, INT_MAX at A[-1] and INT_MAX at A[N]. 
  These additions don't change the result, but make the implementation easier: If any L falls out of the left 
  boundary of the array, then L = INT_MIN, and if any R falls out of the right boundary, then R = INT_MAX.
  
  With inuts from Leetcode
  
*/
