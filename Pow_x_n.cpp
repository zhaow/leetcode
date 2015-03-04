/*
 * Author	: ZhaoW
 * Time		: 2015-03-04  13:57:31
 * problem	: https://oj.leetcode.com/problems/powx-n/
 Implement pow(x, n). 
 * no compile
 */

#include <iostream>
#include <math>

using namespace std;
 
class Solution {
public:
    double pow(double x, int n) {
		if (x == 0.0)
            return 0.0;
        if (x == 1.0)
            return 1.0;
        if (x == -1.0)
            return (n%2) ? -1.0 : 1.0;
        if (n == 0)
            return 1;
        if (n < 0)
            return pow(1/x, -n);
        if (n == 2)
            return x*x;
        
        return pow(pow(x, n/2), 2) * ((n%2) ? x : 1);
    }
};

int main()
{
	Solution myTest;
	cout << myTest.pow(1.2, 2);
	return 0;
}