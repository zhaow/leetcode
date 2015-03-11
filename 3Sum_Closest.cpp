/*
 * Author	: ZhaoW
 * Time		: 2015-03-11 13:38:50
 * problem	: https://leetcode.com/problems/3sum-closest/
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int ans, dis;
        int size = num.size();
		
		ans = num[0] + num[1] + num[2];
        dis = abs(ans - target);
            
        sort(num.begin(), num.end());
        //<i, j, k>
        for (int i = 0; i < size - 2; i++){
            int j = i + 1, k = size - 1;
            while (j < k){
                int sum = num[i] + num[j] + num[k];
				
				int tmp = abs(sum -target);
				
				if (tmp < dis) {
					dis = tmp;
					ans = sum;
				}
				
                else if (sum < target) {
                    j++;
                }
                else{  // sum > 0  
                    k--;
                }
            }
        }
        return ans;
    }
};

int main()
{
	vector<int> A;
	Solution myTest;
	
	while (true)
	{
		int size, tmp;
		cin >> size;
		for (int i=0; i<size; i++)
		{
			cin >> tmp;
			A.push_back(tmp);
		}
		myTest.threeSumClosest(A, 1);
	}
	
	return 0;
}