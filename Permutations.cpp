/*
 * Author	: ZhaoW
 * Time		: 2015-03-27 14:40:42
 * problem	: https://leetcode.com/problems/permutations/
  Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<vector<int> > permute(vector<int> &num) {
			vector<vector<int> > ans;
			
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
			int len = num.size();
			for (int i=pos; i<len; i++)
			{
				swap(num[pos], num[i]);
				permute_foo(num, pos+1, ans);
				swap(num[pos], num[i]);
			}
		}
};

int main()
{
	
}
