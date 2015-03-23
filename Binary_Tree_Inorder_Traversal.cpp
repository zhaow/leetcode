/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 13:32:42
 * problem	: https://leetcode.com/problems/binary-tree-inorder-traversal/
 Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
		vector<TreeNode*> s;
		TreeNode *p = root;
		
		while (!s.empty() || p!=NULL)
		{
			if (p!=NULL)
			{
				s.push_back(p);
				p = p->left;
			}
			else
			{
				p = s.back();
				s.pop_back();
				ans.push_back(p->val);
				p = p->right;
			}
		}
		return ans;
    }
};

int main()
{
	return 0;
}
