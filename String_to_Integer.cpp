/*
 * Author	: ZhaoW
 * Time		: 2015-03-16 14:43:15
 * problem	: https://leetcode.com/problems/string-to-integer-atoi/
 Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. 
*/

#include <iostream>
#include <string>
#include <limits>
#include <cstring>

using namespace std;
/*
class Solution {
public:
    int atoi(string str) {
        int num = 0;
		int sign = 1;
		const int n = str.size();
		int i = 0;
		while (str[i] == ' ' && i < n) i++;
		if (str[i] == '+') {
			i++;
		} else if (str[i] == '-') {
			sign = -1;
			i++;
		}
		for (; i < n; i++) {
			if (str[i] < '0' || str[i] > '9')
			break;
			if (num > INT_MAX / 10 ||
			(num == INT_MAX / 10 &&
			(str[i] - '0') > INT_MAX % 10)) {
				return sign == -1 ? INT_MIN : INT_MAX;
			}
		num = num * 10 + str[i] - '0';
		}
		return num * sign;
    }
};
/**/
int func(int x)
{
	int countx =0;
	while(x)
	{
		countx ++;
		x = x&(x-1);
	}
	return countx;
} 

int main()
{
	while (1)
	{
		int tmp;
		cin >> tmp;
		cout << func(tmp) << endl;
	}
	return 0;
}
