/*
 * Author	: ZhaoW
 * Time		: 2015-03-24 15:33:42
 * problem	: https://leetcode.com/problems/merge-two-sorted-lists/
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */
#include <iostream>
#include <vector>

using namespace std;
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode newHead(0);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p = &newHead;
		
		while (p1 && p2)
		{
			if (p1->val < p2->val)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				p2 = p2->next;
			}
			p  = p->next;
		}
		
		if (p1)
			p->next = p1;
		else
			p->next = p2;
		
		return newHead.next;
    }
}; 
 
int main()
{
 
}
 