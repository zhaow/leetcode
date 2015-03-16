/*
 * Author	: ZhaoW
 * Time		: 2015-03-16 14:15:15
 * problem	: https://leetcode.com/problems/reorder-list/
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return;
		ListNode *slow = head, *fast = head, *prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr; // cut at middle
		slow = reverse(slow);
		// merge two lists
		ListNode *curr = head;
		while (curr->next) {
			ListNode *tmp = curr->next;
			curr->next = slow;
			slow = slow->next;
			curr->next->next = tmp;
			curr = tmp;
		}
		curr->next = slow;
	}
	ListNode* reverse(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *prev = head;
		for (ListNode *curr = head->next, *next = curr->next; curr;
			prev = curr, curr = next, next = next ? next->next : nullptr) {
			curr->next = prev;
		}
		head->next = nullptr;
		return prev;
	}
};

int main()
{
	return 0;
}
