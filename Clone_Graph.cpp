/*
 * Author	: ZhaoW
 * Time		: 2015-03-02 14:01:44
 * problem	: https://oj.leetcode.com/problems/clone-graph/
  Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		map<int, UndirectedGraphNode*> newTable;
		queue<UndirectedGraphNode*> bfsList;
		
		if (node == NULL)
			return NULL;
		
		bfsList.push(node);
		while(!bfsList.empty()) {
			UndirectedGraphNode* ptr = bfsList.front();
			bfsList.pop();
			if (newTable.find(ptr->label)==newTable.end()) {
				UndirectedGraphNode* new_node = new UndirectedGraphNode(ptr->label);  
                newTable.insert(pair<int, UndirectedGraphNode*>(new_node->label, new_node));  
                for(int i=0;i<ptr->neighbors.size();i++)  
                {  
                    bfsList.push(ptr->neighbors[i]);  
                }  
			}
		}
		
		bfsList.push(node);
		while(!bfsList.empty()) {
			UndirectedGraphNode* ptr = bfsList.front();
			bfsList.pop();
			UndirectedGraphNode* tmp = newTable[ptr->label];
			if (tmp->neighbors.empty() && !ptr->neighbors.empty()) {
				vector<UndirectedGraphNode *>::iterator ite;
				for (ite = ptr->neighbors.begin(); ite!=ptr->neighbors.end(); ite++) {
					tmp->neighbors.push_back(newTable[(*ite)->label]);
					bfsList.push((*ite));
				}
			}
		}
		
		return newTable[node->label];
    }
};

int main()
{
	Solution myTest;
	myTest.cloneGraph(NULL);
	return 0;
}
