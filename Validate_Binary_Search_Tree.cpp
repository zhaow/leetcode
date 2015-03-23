/*
 * Author	: ZhaoW
 * Time		: 2015-03-23 18:46:42
 * problem	: https://leetcode.com/problems/validate-binary-search-tree/
  Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        if (root==NULL)
            return true;
		return isValid(root->left, LONG_MIN, root->val)
		  && isValid(root->right, root->val, LONG_MAX);
    }
private:
	bool isValid(TreeNode *root, long minv, long maxv)
	{
		if (root == NULL)
			return true;
		return (root->val>minv) && (root->val<maxv)
			&& isValid(root->left, minv, (long)root->val)
			&& isValid(root->right,(long)root->val, maxv);
	}
};

int main()
{
	return 0;
}

