/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 10:06:42
 * problem	: https://leetcode.com/problems/longest-valid-parentheses/
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
		int i;
		stack<int> cache;
		
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '(')
			{
				cache.push(0);
			}
			else if (!cache.empty())
			{
				int sum = 0;
				while (!cache.empty() && cache.top())
				{
					sum += cache.top();
					cache.pop();
				}
				if (cache.empty())
				{
					if (sum > ans)
						ans = sum;
				}
				else
				{
					cache.pop();
					cache.push(sum+2);
				}
			}
		}
		
		while (!cache.empty())
		{
			int sum = 0;
			while (!cache.empty() && cache.top())
			{
				sum += cache.top();
				cache.pop();
			}
			if (!cache.empty())
				cache.pop();
			if (sum > ans)
			{
				ans = sum;
			}
		}
		return ans;
    }
};

int main()
{
	Solution myTsest;
	while (true)
	{
		string s;
		cin >> s;
		cout << myTsest.longestValidParentheses(s) << endl;
	}
	return 0;
}
