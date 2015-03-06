/*
 * Author	: ZhaoW
 * Time		: 2015-03-05  11:05:36
 * problem	: https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	typedef vector<int>::size_type sz_type;
	
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		myInorder.assign(inorder.begin(), inorder.end());
		myPostorder.assign(postorder.begin(), postorder.end());
		
        return constructTree(0, myInorder.size(), 0, myPostorder.size());
    }
private:
	vector<int> myInorder;
	vector<int> myPostorder;
	
	TreeNode *constructTree(sz_type istart, sz_type iend, sz_type pstart, sz_type pend)
	{
		if (istart>=iend || pstart>=pend)
			return NULL;
		
		TreeNode *root = new TreeNode(myPostorder[pend-1]); 
		
		vector<int>::iterator cut;
		cut = find(myInorder.begin()+istart, myInorder.begin()+iend, myPostorder[pend-1]);
		
		int cut_pos = cut - myInorder.begin() - istart;
		
		root->left = constructTree(istart, istart+cut_pos, pstart, pstart+cut_pos);
		root->right= constructTree(istart+cut_pos+1, iend, pstart+cut_pos, pend-1);
		
		return root;
	}
};

int main()
{
	Solution myTest;
	
	TreeNode *root=NULL;
	
	vector<int> inorder;
	vector<int> postorder;
	int size, tmp;
	
	while(true)
	{
		cin >> size;
		inorder.clear();
		postorder.clear();
		
		for (int i=0; i<size; i++)
		{
			cin >> tmp;
			inorder.push_back(tmp);
		}
		
		for (int i=0; i<size; i++)
		{
			cin >> tmp;
			postorder.push_back(tmp);
		}
		
		root = myTest.buildTree(inorder, postorder);
	}
	
	return 0;
}
