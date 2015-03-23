/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 14:25:42
 * problem	: https://leetcode.com/problems/recover-binary-search-tree/
  Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL;
		TreeNode *p = root;
		
		first = NULL;
		second = NULL;
		while (p)
		{
			if (p->left == NULL)
			{
				detect(p, prev);
				prev = p;
				p = p->right;
			}
			else
			{
				TreeNode *tmp = p->left;
				while (tmp->right && tmp->right!=p)
					tmp = tmp->right;
				if (tmp->right == NULL)
				{
					tmp->right = p;
					p = p->left;
				}
				else
				{
					detect(p, prev);
					tmp->right = NULL;
					prev = p;
					p = p->right;
				}
			}
		}
		if (first && second)
		    swap(first->val, second->val);
		return ;
    }
private:
	TreeNode *first;
	TreeNode *second;
	void detect(TreeNode* p, TreeNode *prev)
	{
		if (prev && p->val < prev->val)
		{
			if (first==NULL)
			{
				first = prev;
				second= p;
			}
			else
				second = p;
		}
	}
};

int main()
{
	return 0;
}	

