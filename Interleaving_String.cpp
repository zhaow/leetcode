/*
 * Author	: ZhaoW
 * Time		: 2015-03-27 16:01:42
 * problem	: https://leetcode.com/problems/interleaving-string/
  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool> > table;
		
		if (s1.empty())
			return s2 == s3;
		if (s2.empty())
			return s1 == s3;
		
		if (s1.empty() && s2.empty() && !s3.empty())
			return false;
		
		if (s1.size()+s2.size() != s3.size())
			return false;
		
		vector<bool> a(s1.size()+1, false);
		table.assign(s2.size()+1, a);
		
		table[0][0] = true;
	
		for (int i=1; i<=s1.size(); i++)
		{
			table[0][i] = (table[0][i-1] && s1[i-1]==s3[i-1]);
		}
		
		for (int i=1; i<=s2.size(); i++)
		{
			table[i][0] = (table[i-1][0] && s2[i-1]==s3[i-1]);
		}
		
		for (int i=1; i<=s2.size(); i++)
		{
			for (int j=1; j<=s1.size(); j++)
			{
				table[i][j] = (table[i][j-1] && s1[j-1]==s3[i+j-1])
							||(table[i-1][j] && s2[i-1]==s3[i+j-1]);
			}
		}
		
		for (int i=0; i<=s2.size(); i++)
		{
			for (int j=0; j<=s1.size(); j++)
			{
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
		return table[s2.size()][s1.size()];
    }
};

int main()
{
	Solution myTest;
	string a, b, c;
	
	vector<int> tt(20, 0);
	int i;
	for (i=0; i<tt.size(); i++)
	{
		tt[i] = i;
	}
	tt.erase(tt.rend()-7, tt.rend()-3);
	//swap_ranges(tt.begin()+3, tt.begin()+7, tt.rbegin()).base();
	for (i=0; i<tt.size(); i++)
	{
		cout << tt[i] << " ";
	}
	cout << endl;
	//cin >> a >> b >> c;
	
	
	//myTest.isInterleave(a, b, c);
	
	while(true);
	return 0;

}