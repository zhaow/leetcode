/*
 * Author	: ZhaoW
 * Time		: 2015-03-18 15:08:42
 * problem	: https://leetcode.com/problems/anagrams/
 Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		unordered_map<string, int> cache;
		typedef unordered_map<string, int>::iterator ISI;
		
		
		if (strs.size()<=1)
			return ans;
		
		for (int i=0; i<strs.size(); i++)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			ISI ite = cache.find(tmp);
			
			if (ite != cache.end())
			{
				if (ite->second != -1)
				{
					ans.push_back(strs[ite->second]);
					ite->second = -1;
				}
				ans.push_back(strs[i]);
			}
			else
			{
				cache.insert(make_pair(tmp, i));
			}
			
		}
		return ans;
    }
};

int main()
{
	return 0;
}