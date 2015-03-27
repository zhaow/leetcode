/*
 * Author	: ZhaoW
 * Time		: 2015-03-26 15:4:42
 * problem	: https://leetcode.com/problems/subsets/
  Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		ans.clear();
		if (S.empty())
			return ans;
		vector<int> tmp;
		foo(S, tmp);
		return ans;
    }
private:
	vector<vector<int> > ans;
	void foo(vector<int> &S, vector<int> &res)
	{
		if (S.empty())
		{
			ans.push_back(res);
		}
		else
		{
			int tmp = S.front();
			S.erase(S.begin());
			foo(S, res);
			res.push_back(tmp);
			foo(S, res);
			res.pop_back();
			S.insert(S.begin(), tmp);
		}
		return ;
	}
};

int main()
{
	return 0;
}
