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
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(0), next(next) {}
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

	// Test Case 2
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	ListNode *reverseList = oSolution.reverseList(head);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;

	// Test Case 1
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);
	reverseList = oSolution.reverseList(head1);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;

	// Test Case 3
	ListNode *head2 = nullptr;
	reverseList = oSolution.reverseList(head2);
	cout << "The reversed list is: ";
	while (reverseList != NULL) {
		cout << reverseList->val << " ";
		reverseList = reverseList->next;
	}
	cout << endl;
	system("pause");
}
