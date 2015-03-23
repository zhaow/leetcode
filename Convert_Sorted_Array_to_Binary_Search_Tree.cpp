/*
 * Author	: ZhaoW
 * Time		: 2015-03-23 19:16:42
 * problem	: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
			return NULL;
		TreeNode *root = new TreeNode(*(num.begin()+(num.size()/2)));
		vector<int> left(num.begin(), num.begin()+(num.size()/2));
		root->left = sortedArrayToBST(left);
		vector<int> right(num.begin()+(num.size()/2)+1, num.end());
		root->right= sortedArrayToBST(right);
		
		return root;
    }
};

int main()
{
	return 0;
}
 