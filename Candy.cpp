/*
 * Author	: ZhaoW
 * Time		: 2015-03-13 14:53:35
 * problem	: https://leetcode.com/problems/candy/
  There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
		const int n = ratings.size();
		vector<int> increment(n);
		
		for (int i = 1, inc = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;
		}
		for (int i = n - 2, inc = 1; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;
		}
		return accumulate(&increment[0], &increment[0]+n, n);
    }
	
};

int main()
{
	
	return 0;
}
