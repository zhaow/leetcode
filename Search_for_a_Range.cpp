/*
 * Author	: ZhaoW
 * Time		: 2015-03-26 15:05:42
 * problem	: https://leetcode.com/problems/search-for-a-range/
 Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans;
		int begin = -1;
		int end = -1;
		
		if (n == 0)
		{
			ans.push_back(begin);
			ans.push_back(end);
			return ans;
		}
		
        int tmp = binarySearch(A, 0, n, target);
		while (tmp != -1)
		{
			begin = tmp;
			tmp = binarySearch(A, 0, begin, target);
		}
		
		if (begin != -1)
		{
			end = begin;
			tmp = binarySearch(A, end+1, n, target);
			while (tmp != -1)
			{
				end = tmp;
				tmp = binarySearch(A, end+1, n, target);
			}
		}
		
		ans.push_back(begin);
		ans.push_back(end);
		
		return ans;
    }
private:
	int binarySearch(int A[], int begin, int end, int target)
	{
		int left = begin;
		int right= end;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (target == A[mid])
				return mid;
			if (A[mid] < target)
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
		return -1;
	}
};

int main()
{
	return 0;
}
