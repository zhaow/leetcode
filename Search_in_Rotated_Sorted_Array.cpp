/*
 * Author	: ZhaoW
 * Time		: 2015-03-09 13:35:11
 * problem	: https://leetcode.com/problems/search-in-rotated-sorted-array/
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>

class Solution {
public:
    int search(int A[], int n, int target) {
		int left=0, right=n, mid;
		
		while(left!=right)
		{
			mid = left + (right - left) /2;
			if (A[mid] == target)
				return mid;
			else if (A[left] <= A[mid])
			{
				if (A[mid] > target && A[left] <= target)
					right = mid;
				else 
					left = mid +1;
			} else {
				if (A[mid] < target && A[right-1] >= target)
					left = mid + 1;
				else
					right = mid;
 			}
		}
		return -1;
    }
};

int main()
{
	Solution myTest;
	int A[8] = {4, 5, 6, 7, 0, 1, 2};
	while(true)
	{
		int tmp;
		std::cin >> tmp;
		std::cout << myTest.search(A, 8, tmp) << std::endl;
	}
	return 0; 
}
