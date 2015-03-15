/*
 * Author	: ZhaoW
 * Time		: 2015-03-15 15:26:42
 * problem	: https://leetcode.com/problems/rotate-list/
 Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k == 0) 
			return head;
		int len = 1;
		ListNode* p = head;
		while (p->next) {
			len++;
			p = p->next;
		}
		k = len - k % len;
		p->next = head;
		for(int step = 0; step < k; step++) {
			p = p->next;
		}
		head = p->next;
		p->next = nullptr;
		return head;
    }
};

int main()
{
	
	return 0;
}
