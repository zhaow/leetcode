/*
 * Author	: ZhaoW
 * Time		: 2015-03-12 13:37:16
 * problem	: https://leetcode.com/problems/permutation-sequence/
 The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		//康托编码
		string tmp;
		string ans;
		int base=1;
		
		for (int i=0; i<n; i++)
		{
			base *= i+1;
			tmp.push_back(i+1+'0');
		}
		
		int tmpk = k-1;
		for (int i=0; i<n; i++ )
		{
			base /= (n-i);
			int pos = tmpk/base;
			ans.push_back(tmp[pos]);
			tmp.erase(tmp.begin()+pos);
			
			tmpk %= base;
		}
		return ans;
    }
};

int main()
{
	int n, k;
	Solution myTest;
	
	while (true)
	{
		cin >> n;
		cin >> k;
		cout << myTest.getPermutation(n, k) << endl;
	}
	return 0;
}