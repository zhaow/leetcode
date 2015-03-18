/*
 * Author	: ZhaoW
 * Time		: 2015-03-18 14:33:42
 * problem	: https://leetcode.com/problems/integer-to-roman/
 Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		const int stand[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string name[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		
		string ans;
		
		for (int i=0; i<13 && num; i++)
		{
			if (stand[i] <= num)
			{
				ans = ans + name[i];
				num -= stand[i];
				i=-1;
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
		int t;
		cin>>t;
		cout << myTest.intToRoman(t) << endl;
	}
	return 0;\ 
}
