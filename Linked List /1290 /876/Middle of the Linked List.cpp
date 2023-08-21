/*
*	876. Middle of the Linked List
*	Given the head of a singly linked list, return the middle node of the linked list.
*	If there are two middle nodes, return the second middle node.
*	Example 1: Input: head = [1,2,3,4,5]
*			   Output: [3,4,5]
*			   Explanation: The middle node of the list is node 3.
*	Example 2: Input: head = [1,2,3,4,5,6]
*			   Output: [4,5,6]
*			   Explanation: Since the list has two middle nodes with values 3 and 4, 
*							        we return the second one.
*	Constraints:
*	The number of nodes in the list is in the range [1, 100].
*	1 <= Node.val <= 100
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
	ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

void main() {
	Solutuon oSolution;

	// Test Case 1
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	ListNode *middle = oSolution.middleNode(head);
	cout << "The middle node of the list is: ";
	while (middle != NULL) {
		cout << middle->val << " ";
		middle = middle->next;
	}
	cout << endl;

	// Test Case 2
	head->next->next->next->next->next = new ListNode(6);
	middle = oSolution.middleNode(head);
	cout << "The middle node of the list is: ";
	while (middle != NULL) {
		cout << middle->val << " ";
		middle = middle->next;
	}
	cout << endl;

	system("pause");
}

/*
Output:
The middle node of the list is: 3 4 5
The middle node of the list is: 4 5 6
*/
