/*
 * Author	: ZhaoW
 * Time		: 2015-03-04 16:46:45
 * problem	: https://oj.leetcode.com/problems/rotate-array/
 Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
*/

#include <iostream>

using namespace std;

class Solution {
public:
   void rotate(int nums[], int n, int k) {
		int i, j;
		if (k==0)
		    return ;
		k = k%n;
		for (i=0, j=n-k-1; i<j; i++, j--)
		{
			swap(nums[i], nums[j]);
		}
		
		for (i=n-k, j=n-1; i<j; i++, j--)
		{
			swap(nums[i], nums[j]);
		}
		
		for (i=0, j=n-1; i<j; i++, j--)
		{
			swap(nums[i], nums[j]);
		}
    }
};

int main()
{
	int Array[7] = {1, 2, 3, 4, 5, 6, 7};
	Solution myTest;
	myTest.rotate(Array, 2, 0);
	for (int i=0; i<7; i++)
		cout << Array[i] << " ";
	cout << endl;
	cin >> Array[1];
	cout << Array[1];
	return 0;
}
