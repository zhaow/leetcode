/*
 * Author	: ZhaoW
 * Time		: 2015-03-06 11:13:40
 * problem	: https://oj.leetcode.com/problems/swap-nodes-in-pairs/
  Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode *p;
		ListNode *tmp;
		
		if (head == NULL || head->next == NULL)
			return head;
		
        if (head->next != NULL)
		{
			tmp = head;
			head = head->next;
			tmp->next = head->next;
			head->next = tmp;
		}
		
		p = head->next;
		
		while (p->next != NULL && p->next->next != NULL)
		{
			tmp = p->next;
			p->next = p->next->next;
			tmp->next=p->next->next;
			p->next->next = tmp;
			
			p = tmp;
		}
		
		return head;
    }
};
