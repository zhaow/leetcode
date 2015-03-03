/*
 * Author	: ZhaoW
 * Time		: 2015-03-02 11:04:27
 * problem	: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
  Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int pos, dup_cnt, i;
		
		if (n == 0)
			return 0;
		
		for (i=1, dup_cnt=0, pos=1; i<n; i++) {
			if (A[pos-1] == A[i]) {
				dup_cnt++;
				if (dup_cnt < 2) {
					A[pos] = A[i];
					pos++;
				}
			} else {
				dup_cnt = 0;
				A[pos] = A[i];
				pos++;
			}
		}
		return pos;
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
	i =  myTest.removeDuplicates(test, i-1);
	
	for (int j=0; j<i; j++)
		cout << test[j] << " ";
	cout << endl;
	
	cin >> i;
	return 0;
}