/*
 * Author	: ZhaoW
 * Time		: 2015-03-27 14:19:42
 * problem	: https://leetcode.com/problems/subsets-ii/
  Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
		ans.clear();
		if (S.empty())
			return ans;
		vector<int> tmp;
		foo(S, tmp, 0);
		
		sort(ans.begin(), ans.end());
		vector<vector<int> >::iterator ite = unique(ans.begin(), ans.end());
		ans.erase(ite, ans.end());
		return ans;
    }
private:
	vector<vector<int> > ans;
	void foo(vector<int> &S, vector<int> &res, int pos)
	{
		if (pos == S.size())
		{
			ans.push_back(res);
		}
		else
		{
			int tmp = S[pos];
			foo(S, res, pos+1);
			res.push_back(tmp);
			foo(S, res, pos+1);
			res.pop_back();
		}
		return ;
	}
};

int main()
{
	return 0;
}