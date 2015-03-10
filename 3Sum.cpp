/*
 * Author	: ZhaoW
 * Time		: 2015-03-10 14:54:42
 * problem	: https://leetcode.com/problems/3sum/
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > triples;
        vector<int> triple;
        int jj, kk;
        int size = num.size();
        if (size < 3)
            return triples;
        sort(num.begin(), num.end());
        //<i, j, k>
        for (int i = 0; i < size - 2; i++){
            if (num[i] > 0)
                break;
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int j = i + 1, k = size - 1;
            while (j < k){
                int sum = num[i] + num[j] + num[k];
                if (sum == 0){
                    triple.push_back(num[i]);
                    triple.push_back(num[j]);
                    triple.push_back(num[k]);
                    triples.push_back(triple);
                    triple.clear();
                    jj = num[j];
                    j++;
                    while (j < k && num[j] == jj)
                        j++;
                }
                else if (sum < 0){
                    jj = num[j];
                    j++;
                    while (j < k && num[j] == jj)
                        j++;
                }
                else{  // sum > 0  
                    kk = num[k];
                    k--;
                    while (k > j && num[k] == kk)
                        k--;
                }
            }
        }
        return triples;
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
		myTest.threeSum(A);
	}
	
	return 0;
}

