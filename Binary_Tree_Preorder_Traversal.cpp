/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 11:55:42
 * problem	: https://leetcode.com/problems/binary-tree-preorder-traversal/
 Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3]. 
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
		vector<TreeNode*> s;
		
		s.push_back(root);
		
		while (!s.empty())
		{
			TreeNode *t = s.back();
			s.pop_back();
			if (t != NULL)
			{
				ans.push_back(t->val);
				if (t->right) 
					s.push_back(t->right);
				if (t->left)
					s.push_back(t->left);
			}
		}
		return ans;
    }
};

int main()
{
	return 0;
}
