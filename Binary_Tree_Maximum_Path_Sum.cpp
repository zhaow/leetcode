/*
 * Author	: ZhaoW
 * Time		: 2015-03-24 14:40:42
 * problem	: https://leetcode.com/problems/binary-tree-maximum-path-sum/
  Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
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
    int maxPathSum(TreeNode *root) {
        ans = INT32_MIN;
		pathSum(root);
		
		return ans;
    }
private:
	int ans;
	int pathSum(TreeNode *root)
	{
		if (root == NULL)
			return 0;
			
		int leftSum = pathSum(root->left);
		int rightSum= pathSum(root->right);
		
		int sum = root->val;
		
		if (leftSum > 0)
			sum += leftSum;
		
		if (rightSum > 0)
			sum += rightSum;
		
		if (sum > ans)
			ans = sum;
		return max(leftSum, rightSum) > 0 ? max(leftSum, rightSum) + root->val : root->val;
	}
};

int main()
{
	
	return 0;
}
