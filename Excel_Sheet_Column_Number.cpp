/*
 * Author	: ZhaoW
 * Time		: 2015-03-02 09:23:55
 * problem	: https://oj.leetcode.com/problems/excel-sheet-column-number/
 * Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {}
	
    int titleToNumber(string s) {
        int ans = 0;
		for (string::size_type i=0; i<s.size(); i++) {
			ans = ans*26 + s[i] -'A' + 1;
		}
		return ans;
    }
};

int main()
{
	string Input;
	Solution myTest;
	
	while(cin >> Input) {
		cout << myTest.titleToNumber(Input);
	}
	return 0;
}
