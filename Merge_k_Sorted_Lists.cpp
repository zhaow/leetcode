/*
 * Author	: ZhaoW
 * Time		: 2015-03-25 13:57:42
 * problem	: https://leetcode.com/problems/merge-k-sorted-lists/
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
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
	struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };
	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, comparator> heap;
		
		if (lists.empty())
			return NULL;
		
		for (int i=0; i<lists.size(); i++)
		{
			if (lists[i] != NULL)
				heap.push(lists[i]);
		}
		
		ListNode newHead(-1);
		ListNode *p = &newHead;

		while (!heap.empty())
		{
			p->next = heap.top();
			heap.pop();
			p = p->next;
			if (p->next && !heap.empty())
			{
				heap.push(p->next);
			}
		}
		return newHead.next;
    }
private:
	
};

void printq(priority_queue<int, vector<int>, greater<int> > p)
{
	while (!p.empty())
	{
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}

int main()
{
	int i;
	priority_queue<int, vector<int>, greater<int> > pqueue;
	
	for (i=0; i<10; i++)
	{
		int tmp = rand()%11;
		pqueue.push(tmp);
	}
	printq(pqueue);
	while (true)
	{
		cin >> i;
		pqueue.push(i);
		printq(pqueue);
	}
	return 0;
}
 