/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 14:16:42
 * problem	: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<TreeNode*> q;
		vector<vector<int> > ans;
		vector<int> lev;
		int cnt = 0;
		
		if (root == NULL)
			return ans;
		
		q.push_back(root);
		int i = 1;
		bool reverse = false;
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
				vector<int> tmp;
				if (reverse)
					tmp.assign(lev.rbegin(), lev.rend());
				else
					tmp = lev;
				ans.push_back(tmp);
				lev.clear();
				i=cnt;
				cnt=0;
				reverse = !reverse;
			}
		}
		
		
		return ans;
    }
};

int main()
{
	return 0;
}
