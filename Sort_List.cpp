/*
 * Author	: ZhaoW
 * Time		: 2015-03-25 15:12:42
 * problem	: https://leetcode.com/problems/sort-list/
 * Sort a linked list in O(n log n) time using constant space complexity.
 */
 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)return head;

		ListNode *fast = head, *slow = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(slow);
		return mergeTwoLists(l1, l2);
    }
private:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode newHead(0);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p = &newHead;
		
		if (l1==l2)
			return l1;
		
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
 