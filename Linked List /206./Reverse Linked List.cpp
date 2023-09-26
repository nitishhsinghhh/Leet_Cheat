/*
*	206. Reverse Linked List
*	Given the head of a singly linked list, return the reverseList node of the linked list.
*	Example 1: Input: head = [1,2,3,4,5]
*			   Output: [5,4,3,2,1]
*	Example 2: Input: head = [1,2]
*			   Output: [2, 1]
*	Example 3:	Input: head = []
*				Output: []
*	Constraints:
*	The number of nodes in the list is the range [0, 5000].
*	-5000 <= Node.val <= 5000
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prevNode = nullptr;
		for (ListNode* currNode = head; currNode != nullptr; ) {
			ListNode* nextNode = currNode->next;
			currNode->next = prevNode;
			prevNode = currNode;
			currNode = nextNode;
		}
		return prevNode;
	}
};

void main() {
	Solution oSolution;

	// Test Case 1
	ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode *reverseList = oSolution.reverseList(head);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;

	// Test Case 2
	head = new ListNode(1, new ListNode(2));
	reverseList = oSolution.reverseList(head);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;

	// Test Case 3
	head = nullptr;
	reverseList = oSolution.reverseList(head);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;
	system("pause");
}

/*
Output:
The reversed list is: 5 4 3 2 1
The reversed list is: 2 1
The reversed list is:
*/
