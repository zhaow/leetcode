/*
 * Author	: ZhaoW
 * Time		: 2015-03-04 14:57:03
 * problem	: https://oj.leetcode.com/problems/palindrome-partitioning-ii/
  Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
int minCut(string s) 
	{
        vector<int> ans(s.size()+1, 0);
		string::size_type i, mid;
		
		for (int i=0; i<ans.size(); i++)
			ans[i] = i-1;
		
		for (mid=0; mid<s.size(); mid++)
		{
			for (i=0; mid-i>=0 && mid+i<s.size() && s[mid-i]==s[mid+i]; i++)
			{//odd
				ans[mid+i+1] = min(ans[mid+i+1], 1+ans[mid-i]);
			}
			
			for (i=1; mid-i+1>=0 && mid+i<s.size() && s[mid-i+1]==s[mid+i]; i++)
			{//even
				ans[mid+i+1] = min(ans[mid+i+1], 1+ans[mid-i+1]);
			}
			
		}
		return ans[s.size()];
    }
};

int main()
{
	Solution myTest;
	string t;
	while(true)
	{
		cin >> t;
		cout << myTest.minCut(t) << endl;
	}
	
}
