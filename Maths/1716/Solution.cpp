#include <iostream>
using namespace std;

class Solution {
public:
	int totalMoney(int days) {
		int totalMoney = 0, weekNumber = 0;
		while (days > 0) {
			if (days < 7) {
				totalMoney += calculateTotal(days + weekNumber, weekNumber);
				days = 0;
			}
			else {
				totalMoney += calculateTotal(7 + weekNumber, weekNumber);
				days -= 7;
				weekNumber++;
			}
		}
		return totalMoney;
	}
private:
	int calculateTotal(int currentDayAmount, int weekNumber) {
		return (currentDayAmount * (currentDayAmount + 1) / 2) - (weekNumber * (weekNumber + 1) / 2);
	}
};

int main() {
	Solution solution;

	// Test case 1: 4 days
	int result1 = solution.totalMoney(4);
	cout << "Total money after 4 days: " << result1 << endl;

	// Test case 2: 10 days
	int result2 = solution.totalMoney(10);
	cout << "Total money after 10 days: " << result2 << endl;

	// Test case 3: 20 days
	int result3 = solution.totalMoney(20);
	cout << "Total money after 20 days: " << result3 << endl;

	system("pause");
	return 0;
}
/*
Output:
Total money after 4 days: 10
Total money after 10 days: 37
Total money after 20 days: 96
*/
