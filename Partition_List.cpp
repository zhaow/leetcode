/*
 * Author	: ZhaoW
 * Time		: 2015-03-14 19:16:42
 * problem	: https://leetcode.com/problems/partition-list/
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
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
    ListNode *partition(ListNode *head, int x) {
		ListNode newHead(0);
		ListNode *ltail = &newHead;
		ListNode *btail = head;
		
		if (head == NULL)
			return head;
		
		newHead.next = head;
		
		while (btail && btail->val < x)
		{
			btail = btail->next;
			ltail = ltail->next;
		}
			
		while (btail && btail->next)
		{
			if (btail->next->val < x)
			{
				ListNode *tmp = ltail->next;
				ltail->next = btail->next;
				btail->next = btail->next->next;
				ltail->next->next = tmp;
				
				ltail = ltail->next;
			}
			else
			{
				btail = btail->next;
			}
		}
		
		return newHead.next;
    }
};

int main()
{
	
	return 0;
}
