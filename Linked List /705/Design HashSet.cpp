/*
*	705. Design HashSet
*	Design a HashSet without using any built-in hash table libraries.
*	Implement MyHashSet class:
*	void add(key) Inserts the value key into the HashSet.
*	bool contains(key) Returns whether the value key exists in the HashSet or not.
*	void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*	Example 1:
*	Input
*	["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
*	[[], [1], [2], [1], [3], [2], [2], [2], [2]]
*	Output
*	[null, null, null, true, false, null, true, null, false]
*	Explanation
*	MyHashSet myHashSet = new MyHashSet();
*	myHashSet.add(1);      // set = [1]
*	myHashSet.add(2);      // set = [1, 2]
*	myHashSet.contains(1); // return True
*	myHashSet.contains(3); // return False, (not found)
*	myHashSet.add(2);      // set = [1, 2]
*	myHashSet.contains(2); // return True
*	myHashSet.remove(2);   // set = [1]
*	myHashSet.contains(2); // return False, (already removed)
*	Constraints:
*	0 <= key <= 106
*	At most 104 calls will be made to add, remove, and contains.
*/

#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(0), next(next) {}
};

class MyHashSet {
private:
	vector<ListNode*> data;
	int hash(int key) {
		return key % data.size();
	}
public:
	MyHashSet() { data.resize(10000); }
	void add(int key) {
		int h = hash(key);
		if (contains(key)) return;
		ListNode* node = new ListNode(key);
		node->next = data[h];
		data[h] = node;
	}

	void remove(int key) {
		int h = hash(key);
		ListNode* node = data[h];
		if (!node) return;
		if (node->val == key) {
			data[h] = node->next;
			delete node;
			return;
		}
		while (node->next) {
			if (node->next->val == key) {
				ListNode* del = node->next;
				node->next = del->next;
				delete del;
				return;
			}
			node = node->next;
		}
	}

	bool contains(int key) {
		int h = hash(key);
		ListNode* node = data[h];
		while (node) {
			if (node->val == key) 
				return true;
			node = node->next;
		}
		return false;
	}
};

void main() {
	// should print 1 (true)
	// should print 0 (false)
	MyHashSet myHashSet;
	myHashSet.add(1);
	myHashSet.add(2);
	cout << myHashSet.contains(1) << endl; 
	cout << myHashSet.contains(3) << endl; 
	myHashSet.add(2);
	cout << myHashSet.contains(2) << endl; 
	myHashSet.remove(2);

	system("pause");
}
/*
Output
1
0
1
*/
