#include <iostream>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int sumS = 0, sumT = 0;
		for (auto i : s)
			sumS += i;

		for (auto n : t)
			sumT += n;

		return char(abs(sumS - sumT));
	}
};

void main() {
	string  s = "abcd", t = "abcde";
	Solution oSolution;
	char res = oSolution.findTheDifference(s, t);

	cout << res << endl;

	system("pause");
}
