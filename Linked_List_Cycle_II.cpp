/*
 * Author	: ZhaoW
 * Time		: 2015-03-16 13:32:15
 * problem	: https://leetcode.com/problems/linked-list-cycle-ii/
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 
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
    ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		
		if (head == NULL || head->next == NULL)
			return NULL;
		
		do
		{
			if (fast->next)
				fast = fast->next->next;
			else
				return NULL;
			slow = slow->next;
		}while (fast && slow && fast != slow);
		
		if (!fast || !slow)
		{
			return NULL;
		}
		else 
		{
			int cycLen = 0;
			fast = head;
			slow = head;
			do
			{
				fast = fast->next->next;
				slow = slow->next;
				cycLen++;
			}while (fast != slow);
			
			fast = head;
			slow = head;
			while (cycLen--)
			{
				fast = fast->next;
			}
			
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
    }
};

int main()
{
	
	return 0;
}
