/*
*	1290. Convert Binary Number in a Linked List to Integer
*	Given head which is a reference node to a singly-linked list. 
*	The value of each node in the linked list is either 0 or 1. 
*	The linked list holds the binary representation of a number.
*	Return the decimal value of the number in the linked list.
*	The most significant bit is at the head of the linked list.
*	Example 1: Input: head = [1,0,1]
*			   Output: 5
*			   Explanation: (101) in base 2 = (5) in base 10
*	Example 2: Input: head = [0]
*			   Output: 0

*	Constraints:
*	The Linked List is not empty.
*	Number of nodes will not exceed 30.
*	Each node's value is either 0 or 1.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(0), next(next) {}
};

class Solutuon {
public:
	int getDecimalValue(ListNode* head) {
		int res = 0;
		while (head !=NULL) {
			res = res * 2 + head->val;
			head = head->next;
		}
		return res;
	}
};

void main() {
	Solutuon oSolution;

	// Test Case 1
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(0);
	head1->next->next = new ListNode(1);
	int res = oSolution.getDecimalValue(head1);
	cout << "The resulting decimal value after converting the binary linked list is.: " << res << endl;

	// Test Case 2
	ListNode *head2 = new ListNode(0);
	res = oSolution.getDecimalValue(head2);
	cout << "The resulting decimal value after converting the binary linked list is.: " << res << endl;

	system("pause");
}

/*
Output: 
The resulting decimal value after converting the binary linked list is.: 5
The resulting decimal value after converting the binary linked list is.: 0
*/
