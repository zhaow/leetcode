/*
 * Author	: ZhaoW
 * Time		: 2015-03-06 10:51:35
 * problem	: https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
		int level_cnt, next_cnt;
		
		if (root == NULL)
			return;
			
		level_queue.push_back(root);
		level_cnt = 1;
		while(!level_queue.empty()) {
			TreeLinkNode *ptr = NULL;
			next_cnt = 0;
			for (int i=0; i<level_cnt && !level_queue.empty(); i++) {
				ptr = level_queue.front();
				level_queue.erase(level_queue.begin());
				if (i == level_cnt-1)
					ptr->next = NULL;
				else
					ptr->next = level_queue.front();
					
				if (ptr->left != NULL)
				{
					next_cnt++;
					level_queue.push_back(ptr->left);
				}
				if (ptr->right != NULL)
				{
					next_cnt++;
					level_queue.push_back(ptr->right);
				}
			}
			level_cnt=next_cnt;
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
