/*
 * Author	: ZhaoW
 * Time		: 2015-03-13 14:27:30
 * problem	: https://leetcode.com/problems/gas-station/
  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> contain;
		
		if (gas.empty())
			return -1;
		
		int ans = 1;
		int min = gas[0] - cost[0];
		contain.push_back(min);
		
		for (int i=1; i<gas.size(); i++)
		{
			int tmp = contain[i-1] + gas[i] - cost[i];
			contain.push_back(tmp);
			
			if (tmp < min)
			{
				min = tmp;
				ans = i+1;
			}
		}
		
		if (contain.back() >= 0) 
		{
			return (ans%contain.size());
		} 
		else
		{
			return -1;
		}
    }
};

int main()
{
	return 0;
}
