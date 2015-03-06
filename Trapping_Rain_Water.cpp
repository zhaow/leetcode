/*
 * Author	: ZhaoW
 * Time		: 2015-03-06  10:14:30
 * problem	: https://oj.leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
		int *rwall = new int[n];
		int *lwall = new int[n];
		
		int lmax = A[0];
		int rmax = A[n-1];
		for (int i=1; i<n-1; i++)
		{
			if (A[i] > lmax)
				lmax = A[i];
			lwall[i] = lmax;
			
			if (A[n-i-1] > rmax)
				rmax = A[n-i-1];
			rwall[n-i-1] = rmax;
		}
		
		int ans = 0;
		for (int i=1; i<n-1; i++)
		{
			int wall = (lwall[i] < rwall[i]) ?  lwall[i] : rwall[i];
			if (wall > A[i])
				ans += wall - A[i];
		}
		delete []rwall;
		delete []lwall;
		return ans;
    }
};

int main()
{
	Solution myTest;
	
	int size;
	
	while (true)
	{
		cin >> size;
		
		int *p = new int[size];
		
		for (int i=0; i<size; i++)
		{
			cin >> p[i];
		}
		
		cout << myTest.trap(p, size) << endl;
		delete[] p;
	}
	
	return 0; 
}

