#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1)
			return x;
		int left = 1, right = x;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (mid <= x / mid)
				left = mid + 1;
			else
				right = mid;
		}
		return left - 1;
	}
};

int main() {
	Solution s;

	// Test case 1
	int x1 = 4, expected1 = 2;
	int result1 = s.mySqrt(x1);
	if (result1 == expected1)
		cout << "Test case 1 passed" << endl;
	else
		cout << "Test case 1 failed" << endl;

	// Test case 2
	int x2 = 8, expected2 = 2;
	int result2 = s.mySqrt(x2);
	if (result2 == expected2)
		cout << "Test case 2 passed" << endl;
	else
		cout << "Test case 2 failed" << endl;

	// Test case 3: edge case - 0
	int x3 = 0, expected3 = 0;
	int result3 = s.mySqrt(x3);
	if (result3 == expected3)
		cout << "Test case 3 passed" << endl;
	else
		cout << "Test case 3 failed" << endl;

	// Test case 4: edge case - 1
	int x4 = 1, expected4 = 1;
	int result4 = s.mySqrt(x4);
	if (result4 == expected4)
		cout << "Test case 4 passed" << endl;
	else
		cout << "Test case 4 failed" << endl;

	// Test case 5: large input - 2147395599
	int x5 = 2147395599, expected5 = sqrt(x5);
	int result5 = s.mySqrt(x5);
	if (result5 == expected5)
		cout << "Test case 5 passed" << endl;
	else
		cout << "Test case 5 failed" << endl;

	// Test case 6: input = 2
	int x6 = 2, expected6 = 1;
	int result6 = s.mySqrt(x6);
	if (result6 == expected6)
		cout << "Test case 6 passed" << endl;
	else
		cout << "Test case 6 failed" << endl;

	// Test case 7: input = 3
	int x7 = 3, expected7 = 1;
	int result7 = s.mySqrt(x7);
	if (result7 == expected7)
		cout << "Test case 7 passed" << endl;
	else
		cout << "Test case 7 failed" << endl;

	// Test case 8: input = 10
	int x8 = 10, expected8 = 3;
	int result8 = s.mySqrt(x8);
	if (result8 == expected8)
		cout << "Test case 8 passed" << endl;
	else
		cout << "Test case 8 failed" << endl;

	// Test case 9: input = 16
	int x9 = 16, expected9 = 4;
	int result9 = s.mySqrt(x9);
	if (result9 == expected9)
		cout << "Test case 9 passed" << endl;
	else
		cout << "Test case 9 failed" << endl;

	// Test case 10: input = 25
	int x10 = 25, expected10 = 5;
	int result10 = s.mySqrt(x10);
	if (result10 == expected10)
		cout << "Test case 10 passed" << endl;
	else
		cout << "Test case 10 failed" << endl;

	// Test case 11: input = 99
	int x11 = 99, expected11 = 9;
	int result11 = s.mySqrt(x11);
	if (result11 == expected11)
		cout << "Test case 11 passed" << endl;
	else
		cout << "Test case 11 failed" << endl;

	// Test case 12: input = 100
	int x12 = 100, expected12 = 10;
	int result12 = s.mySqrt(x12);
	if (result12 == expected12)
		cout << "Test case 12 passed" << endl;
	else
		cout << "Test case 12 failed" << endl;

	// Test case 13: input = 101
	int x13 = 101, expected13 = 10;
	int result13 = s.mySqrt(x13);
	if (result13 == expected13)
		cout << "Test case 13 passed" << endl;
	else
		cout << "Test case 13 failed" << endl;

	// Test case 14: input = 999
	int x14 = 999, expected14 = 31;
	int result14 = s.mySqrt(x14);
	if (result14 == expected14)
		cout << "Test case 14 passed" << endl;
	else
		cout << "Test case 14 failed" << endl;

	// Test case 15: input = 1000
	int x15 = 1000, expected15 = 31;
	int result15 = s.mySqrt(x15);
	if (result15 == expected15)
		cout << "Test case 15 passed" << endl;
	else
		cout << "Test case 15 failed" << endl;

	// Test case 16: input = 1024
	int x16 = 1024, expected16 = 32;
	int result16 = s.mySqrt(x16);
	if (result16 == expected16)
		cout << "Test case 16 passed" << endl;
	else
		cout << "Test case 16 failed" << endl;

	// Test case 17: input = 1025
	int x17 = 1025, expected17 = 32;
	int result17 = s.mySqrt(x17);
	if (result17 == expected17)
		cout << "Test case 17 passed" << endl;
	else
		cout << "Test case 17 failed" << endl;

	// Test case 18: input = 12345
	int x18 = 12345, expected18 = 111;
	int result18 = s.mySqrt(x18);
	if (result18 == expected18)
		cout << "Test case 18 passed" << endl;
	else
		cout << "Test case 18 failed" << endl;

	// Test case 19: input = 123456
	int x19 = 123456, expected19 = 351;
	int result19 = s.mySqrt(x19);
	if (result19 == expected19)
		cout << "Test case 19 passed" << endl;
	else
		cout << "Test case 19 failed" << endl;

	// Test case 20: input = 1234567
	int x20 = 1234567, expected20 = 1110;
	int result20 = s.mySqrt(x20);
	if (result20 == expected20)
		cout << "Test case 20 passed" << endl;
	else
		cout << "Test case 20 failed" << endl;

	// Test case 21: input = 987654321
	int x21 = 987654321, expected21 = 31425;
	int result21 = s.mySqrt(x21);
	if (result21 == expected21)
		cout << "Test case 21 passed" << endl;
	else
		cout << "Test case 21 failed" << endl;

	// Test case 22: input = 2147395599
	int x22 = 2147395599, expected22 = 46339;
	int result22 = s.mySqrt(x22);
	if (result22 == expected22)
		cout << "Test case 22 passed" << endl;
	else
		cout << "Test case 22 failed" << endl;

	// Test case 23: input = 2147483647
	int x23 = 2147483647, expected23 = 46340;
	int result23 = s.mySqrt(x23);
	if (result23 == expected23)
		cout << "Test case 23 passed" << endl;
	else
		cout << "Test case 23 failed" << endl;

	system("pause");

	return 0;
}
/*
Output:
Test case 1 passed
Test case 2 passed
Test case 3 passed
Test case 4 passed
Test case 5 passed
Test case 6 passed
Test case 7 passed
Test case 8 passed
Test case 9 passed
Test case 10 passed
Test case 11 passed
Test case 12 passed
Test case 13 passed
Test case 14 passed
Test case 15 passed
Test case 16 passed
Test case 17 passed
Test case 18 passed
Test case 19 passed
Test case 20 failed
Test case 21 failed
Test case 22 passed
Test case 23 passed
*/
