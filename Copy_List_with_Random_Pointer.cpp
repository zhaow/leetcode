/*
 * Author	: ZhaoW
 * Time		: 2015-03-15 16:45:42
 * problem	: https://leetcode.com/problems/copy-list-with-random-pointer/
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/

#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *newList;
		RandomListNode *tmp;
		RandomListNode *p = head;
		
		if (!head)
			return nullptr;
		
		while (p)
		{
			tmp = new RandomListNode(p->label);
			tmp->next  = p->next;
			tmp->random= p->random;
			p->next    = tmp;
			
			p = p->next->next;
		}
		
		newList = head->next;
		RandomListNode *newp = newList;
		while (newp)
		{
		    if (newp->random)
			    newp->random = newp->random->next;
			if (newp->next)
			    newp = newp->next->next;
			else
			    break;
		}
		p = head;
		newp = newList;
		while (p && newp)
		{
			p->next = p->next->next;
			if (newp->next)
			    newp->next = newp->next->next;
			
			p = p->next;
			newp = newp->next;
		}
		return newList;
    }
};

int main()
{
	
	return 0;
}
