#include <iostream>
using namespace std;

class TotalMoneyCalculator {
public:
	virtual int calculateTotal(int currentDayAmount, int weekNumber) = 0;
};

class DefaultTotalMoneyCalculator : public TotalMoneyCalculator {
public:
	int calculateTotal(int currentDayAmount, int weekNumber) override {
		return (currentDayAmount * (currentDayAmount + 1) / 2) - (weekNumber * (weekNumber + 1) / 2);
	}
};

class WeekMoneyCalculator {
public:
	int calculateTotalMoney(int days, TotalMoneyCalculator& calculator) {
		int totalMoney = 0, weekNumber = 0;
		while (days > 0) {
			if (days < 7) {
				totalMoney += calculator.calculateTotal(days + weekNumber, weekNumber);
				days = 0;
			}
			else {
				totalMoney += calculator.calculateTotal(7 + weekNumber, weekNumber);
				days -= 7;
				weekNumber++;
			}
		}
		return totalMoney;
	}
};

int main() {
	WeekMoneyCalculator calculator;
	DefaultTotalMoneyCalculator defaultCalculator;
	int total = calculator.calculateTotalMoney(30, defaultCalculator);

	// Test case 1: 4 days
	int result1 = calculator.calculateTotalMoney(4, defaultCalculator);
	cout << "Total money after 4 days: " << result1 << endl;

	// Test case 2: 10 days
	int result2 = calculator.calculateTotalMoney(10, defaultCalculator);
	cout << "Total money after 10 days: " << result2 << endl;

	// Test case 3: 20 days
	int result3 = calculator.calculateTotalMoney(20, defaultCalculator);
	cout << "Total money after 20 days: " << result3 << endl;

	system("pause");
	return 0;
}
