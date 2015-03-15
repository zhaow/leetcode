/*
 * Author	: ZhaoW
 * Time		: 2015-03-14 19:41:42
 * problem	: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode newHead(0);
		ListNode *prev = &newHead;
		newHead.next = head;
		
		ListNode *now = prev->next;
		
		while (now)
		{
			int cmp = now->val;
			bool isDup = false;
			while (now->next && now->next->val == cmp)
			{
				isDup = true;
				now->next = now->next->next;
			}
			
			if (isDup)
			{
				prev->next = now->next;
			}
			
			now = prev->next;
		}
		return newHead.next;
    }
};

int main()
{
	
	return 0;
}
