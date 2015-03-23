/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 16:28:42
 * problem	: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
  Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode *root) {
		TreeNode *p = root;
		
		while (p)
		{
			if (p->left == NULL)
			{
				p = p->right;
			}
			else
			{
				TreeNode *tmp = p->left;
				while (tmp->right)
					tmp = tmp->right;
				if (tmp->right == NULL)
				{
					tmp->right = p->right;
					p->right = p->left;
					p->left = NULL;	
					p = p->right;
				}
			}
		}
    }
};

int main()
{
	return 0;
}	
