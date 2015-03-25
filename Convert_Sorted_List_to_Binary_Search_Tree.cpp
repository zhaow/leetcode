/*
 * Author	: ZhaoW
 * Time		: 2015-03-24 14:05:42
 * problem	: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
 
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		ListNode newHead(0);
        ListNode *fast=head;
		ListNode *slow=&newHead;
		
		newHead.next = head;
		
		if (head == NULL)
			return NULL;
		
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		
		TreeNode *root = new TreeNode(slow->next->val);
		root->right= sortedListToBST(slow->next->next);
		
		if (slow->next != head)
		{
			ListNode *tmp = slow->next;
			slow->next = NULL;
			root->left = sortedListToBST(head);
			slow->next = tmp;
		}
		else
		    root->left = NULL;
		return root;
    }
};

int main()
{
	Solution myTest;
	ListNode t(0);
	myTest.sortedListToBST(&t);
	return 0;
}
 