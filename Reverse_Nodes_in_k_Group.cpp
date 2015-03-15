/*
 * Author	: ZhaoW
 * Time		: 2015-03-15 16:12:42
 * problem	: https://leetcode.com/problems/reverse-nodes-in-k-group/
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len = 1;
		ListNode *p = head;
		
		if (head==nullptr || len < k || k<=1)
			return head;
		
		while (p->next)
		{
			len++;
			p = p->next;
		}
			
		ListNode newHead(0);
		ListNode *loopHead = &newHead;
		newHead.next = head;
		p = loopHead->next;
		while (len >= k)
		{
			int cnt = 1;
			while (cnt<k)
			{
				ListNode *tmp = loopHead->next;
				loopHead->next = p->next;
				p->next = p->next->next;
				loopHead->next->next = tmp;
				cnt++;
			}
			loopHead = p;
			if (loopHead)
				p = loopHead->next;
			len -= k;
		}
		return newHead.next;
    }
};

ListNode* add_node(ListNode *head, int a)
{
	ListNode *tmp = new ListNode(a);
	if (!head)
		return tmp;
	ListNode *p = head;
	while (p->next)
		p = p->next;
	p->next = tmp;
	
	return head;
}

int main()
{
	ListNode *head = NULL;
	while (true)
	{
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			int tmp;
			cin >> tmp;
			
			head = add_node(head, tmp);
		}
		int k;
		cin >> k;
		
		Solution myTest;
		myTest.reverseKGroup(head, k);
	}
	return 0;
}
