/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 16:57:42
 * problem	: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
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
	typedef vector<int>::iterator VII;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return construct(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
	
private:
	TreeNode *construct(vector<int> &pre, int psta, int pend, vector<int> &ino, int ista, int iend)
	{
		if (psta==pend || ista==iend)
			return NULL;
		TreeNode *ans = new TreeNode(pre[psta]);
		
		VII pos = find(ino.begin()+ista, ino.begin()+iend, pre[psta]);
		if (pos != ino.begin()+iend)
		{
			int a = pos - ino.begin() - ista;
			ans->left = construct(pre, psta+1, psta+1+a, ino, ista, ista+a);
			ans->right= construct(pre, psta+1+a, pend, ino, ista+a+1, iend);
		}
		return ans;
	}
};

int main()
{
	return 0;
}