#include <iostream>
#include<queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		auto iter = head;
		auto len = 1;
		while (iter->next != nullptr) {
			iter = iter->next; ++len;
		}
    
		// close the list (create a ring)
		iter->next = head;
		iter = head;
    
		// find one element before the new head
		for (int i = 0; i < len - (k % len) - 1; ++i) 
			iter = iter->next;
		
		head = iter->next;
    
		// open the list (break the ring)
		iter->next = nullptr;
		return head;
	}
};

void main() {
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);

	Solution oSolution;
	ListNode* rotated = oSolution.rotateRight(head1, 2);

	while (rotated != nullptr) {
		cout << rotated->val << " ";
		rotated = rotated->next;
	}
	cout << endl;

	ListNode *head2 = new ListNode(0);
	head2->next = new ListNode(1);
	head2->next->next = new ListNode(2);

	ListNode* rotated1 = oSolution.rotateRight(head2, 4);

	while (rotated1 != nullptr) {
		cout << rotated1->val << " ";
		rotated1 = rotated1->next;
	}
	cout << endl;
}

/*
Output:
4 5 1 2 3
2 0 1
*/
