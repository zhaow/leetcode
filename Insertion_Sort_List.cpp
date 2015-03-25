/*
 * Author	: ZhaoW
 * Time		: 2015-03-25 15:00:42
 * problem	: https://leetcode.com/problems/insertion-sort-list/
 Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode newHead(INT32_MIN);
		ListNode *p = &newHead;
		ListNode *tmp=head;
		
		
		while (tmp)
		{
			p = &newHead;
			while (p->next && p->next->val <= tmp->val)
			{
				p = p->next;
			}
			ListNode *next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
			tmp = next;
		}
		return newHead.next;
    }
};

int main()
{
	return 0;
}
 