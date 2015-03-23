/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 13:53:42
 * problem	: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode*> q;
		vector<vector<int> > ans;
		vector<int> lev;
		int cnt = 0;
		
		if (root == NULL)
			return ans;
		
		q.push_back(root);
		int i = 1;
		while (!q.empty())
		{
			TreeNode *p = q.front();
			q.erase(q.begin());
			lev.push_back(p->val);
			i--;
			
			if (p->left)
			{
				q.push_back(p->left);
				cnt++;
			}
			if (p->right)
			{
				q.push_back(p->right);
				cnt++;
			}
				
			if (i==0)
			{
				ans.insert(ans.begin(), lev);
				lev.clear();
				i=cnt;
				cnt=0;
			}
		}
		return ans;
    }
};

int main()
{
	return 0;
}
