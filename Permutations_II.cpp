/*
 * Author	: ZhaoW
 * Time		: 2015-03-27 14:51:42
 * problem	: https://leetcode.com/problems/permutations-ii/
  Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ans;
		ans.clear();
		sort(num.begin(), num.end());
		permute_foo(num, 0, ans);
		return ans;
	}
private:
	void permute_foo(vector<int> &num, int pos, vector<vector<int> > &ans)
	{
		if (pos == num.size())
		{
			ans.push_back(num);
				return ;
		}
		unordered_set<int> swapped;
		int len = num.size();
		for (int i=pos; i<len; i++)
		{
		    if (swapped.find(num[i]) != swapped.end())
				continue;
		
			swapped.insert(num[i]);
			swap(num[pos], num[i]);
			permute_foo(num, pos+1, ans);
			swap(num[pos], num[i]);
		}
	}
};

int main()
{
	vector<int> t = {1, 1, 4, 4};
	Solution myTest;
	myTest.permuteUnique(t);
}
