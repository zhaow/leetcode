/*
 * Author	: ZhaoW
 * Time		: 2015-03-09 14:14:51
 * problem	: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
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
				return true;
			if (A[left] < A[mid])
			{
				if (A[mid] > target && A[left] <= target)
					right = mid;
				else 
					left = mid +1;
			} else if (A[left] > A[mid]){
				if (A[mid] < target && A[right-1] >= target)
					left = mid + 1;
				else
					right = mid;
 			} else {
				left++;
			}
		}
		return false;
    }
};

int main()
{
	Solution myTest;
	const int size = 4;
	int A[size] = {1, 3, 1, 1};
	while(true)
	{
		int tmp;
		std::cin >> tmp;
		std::cout << myTest.search(A, size, tmp) << std::endl;
	}
	return 0; 
}
