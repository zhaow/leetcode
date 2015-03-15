/*
 * Author	: ZhaoW
 * Time		: 2015-03-14 18:47:42
 * problem	: https://leetcode.com/problems/add-two-numbers/
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1->next;
		ListNode *p2 = l2->next;
		ListNode *ans = new ListNode(0);
		ListNode *pa = ans;
		
		ans->val = (l1->val + l2->val)%10;
		int carry = (l1->val + l2->val)/10;
		
		while (p1 || p2)
		{
			ListNode* tmp = new  ListNode(0); 
			tmp->next = NULL;
			if (p1)
				tmp->val = p1->val; 
			if (p2)
				tmp->val += p2->val;
			tmp->val += carry;
			
			carry = tmp->val / 10;
			tmp->val %= 10;

			pa->next = tmp;
			if (p1) p1 = p1->next;
			if (p2) p2 = p2->next;
			pa = tmp;
		}
		
		if (carry)
		{
			ListNode* tmp = new  ListNode(0); 
			tmp->val = carry;
			tmp->next = NULL;
			pa->next = tmp;
		}
		
		return ans;
    }
};

int main()
{
	
	return 0;
}
