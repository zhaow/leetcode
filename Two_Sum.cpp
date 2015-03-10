/*
 * Author	: ZhaoW
 * Time		: 2015-03-10 14:15:57
 * problem	: https://leetcode.com/problems/two-sum/
 Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> table;
		
		vector<int>::size_type i;
		
		vector<int> ans;
		ans.clear();
		for (i=0; i<numbers.size(); i++)
		{
			unordered_map<int, int>::iterator tmp;
			tmp = table.find(target - numbers[i]);
			if (tmp != table.end())
			{
				ans.push_back(tmp->second+1);
				ans.push_back(i+1);
				return ans;
			}
			table[numbers[i]] = i;
		}
		return ans;
    }
};

int main()
{
	return 0;
}
