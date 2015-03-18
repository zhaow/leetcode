/*
 * Author	: ZhaoW
 * Time		: 2015-03-18 14:53:42
 * problem	: https://leetcode.com/problems/roman-to-integer/
 Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
		const int stand[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string name[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		
		while (!s.empty())
		{
			for (int i=0; i<13; i++)
			{
				int j;
				for (j=0; j<name[i].size() && j<s.size() && name[i][j]==s[j]; j++){}
				if (j==name[i].size())
				{
					s.erase(s.begin(), s.begin()+j);
					ans += stand[i];
				}
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
		cin>>t;
		cout << myTest.romanToInt(t) << endl;
	}
	return 0;\ 
}
