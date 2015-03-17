/*
 * Author	: ZhaoW
 * Time		: 2015-03-17 13:45:42
 * problem	: https://leetcode.com/problems/longest-palindromic-substring/
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
 
 #include <iostream>
 #include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
		
		if (s.size() <= 1)
			return s;
		
		const int size = s.size();
		
		for (int i=1; i<s.size()-1; i++)
		{
			int j;
			for (j=1; i-j>=0 && i+j<size && s[i-j]==s[i+j]; j++){}
			
			if ((j-1)*2+1 > ans.size())
			{
				ans.assign(s.begin()+i-j+1, s.begin()+i+j);
			}
			
			
		}
		
		for (int i=0; i<s.size()-1; i++)
		{
			int j;
			for (j=1; i-j+1>=0 && i+j<size && s[i-j+1]==s[i+j]; j++){}
			
			if ((j-1)*2 > ans.size())
			{
				ans.assign(s.begin()+i-j+2, s.begin()+i+j);
			}
		}
		
		return ans;
    }
};

int main()
{
	Solution myTest;
	while (true)
	{
		string t;
		cin >> t;
		cout << myTest.longestPalindrome(t) << endl;
	}
	return 0;
} 