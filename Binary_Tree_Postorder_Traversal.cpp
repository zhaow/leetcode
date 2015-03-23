/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 12:50:42
 * problem	: https://leetcode.com/problems/binary-tree-postorder-traversal/
 Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1]. 
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
		vector<TreeNode*> s;
		
		s.push_back(root);
		
		while (!s.empty())
		{
			TreeNode *t = s.back();
			s.pop_back();
			if (t != NULL)
			{
				ans.insert(ans.begin(), t->val);
				if (t->left)
					s.push_back(t->left);
				if (t->right) 
					s.push_back(t->right);
			}
		}
		return ans;
    }
};

int main()
{
	return 0;
}
