/*
 * Author	: ZhaoW
 * Time		: 2015-03-02 11:04:27
 * problem	: https://oj.leetcode.com/problems/first-missing-positive/
  Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
	//http://blog.csdn.net/nanjunxiao/article/details/12973173
	//原地hash排序
    int firstMissingPositive(int A[], int n) {
		int val, tmp;
        for (int i=0; i<n; i++) {
			val = A[i];
			while (val>0 && val<=n && val != A[val-1]) {
				tmp = A[val-1];
				A[val-1] = val;
				val = tmp;
			}
		}
		for (int i=0; i<n; i++) {
			if (A[i]<=0 || A[i] != i+1)
				return i+1;
		}
		return n+1;
    }

};

int main()
{
	Solution myTest;
	int test[256], i;
	i = 0;
	while (cin >> test[i++]){}
	cin.clear();
	cin.sync();
	cout << myTest.firstMissingPositive(test, i-1);
	cin >> i;
	system("pause");
	return 0;
}