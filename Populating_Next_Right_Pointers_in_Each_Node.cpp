/*
 * Author	: ZhaoW
 * Time		: 2015-03-02 09:23:55
 * problem	: https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
  Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> level_queue;
		int level_cnt;
		
		if (root == NULL)
			return;
			
		level_queue.push_back(root);
		level_cnt = 1;
		while(!level_queue.empty()) {
			TreeLinkNode *ptr = NULL;
			for (int i=0; i<level_cnt && !level_queue.empty(); i++) {/*perfect binary tree*/
				ptr = level_queue.front();
				level_queue.erase(level_queue.begin());
				if (i == level_cnt-1)
					ptr->next = NULL;
				else
					ptr->next = level_queue.front();
					
				if (ptr->left != NULL)
					level_queue.push_back(ptr->left);
				if (ptr->right != NULL)
					level_queue.push_back(ptr->right);
			}
			level_cnt+=level_cnt;
		}
    }
};

int main()
{
	Solution myTest;
	TreeLinkNode root(0);
	
	myTest.connect(&root);
	return 0;
}