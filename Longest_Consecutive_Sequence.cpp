/*
 * Author	: ZhaoW
 * Time		: 2015-03-10 13:32:50
 * problem	: https://leetcode.com/problems/longest-consecutive-sequence/
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(std::vector<int> &num) {
        unordered_map<int, bool> used;
		
		vector<int>::iterator i;
		
		for (i=num.begin(); i!=num.end(); i++)
		{
			used[(*i)] = false;
		}
		
		int longest=0;
		
		for (i=num.begin(); i!=num.end(); i++)
		{
			if (used[(*i)])
				continue;
				
			int l = 1;
			
			used[(*i)] = true;
			for (int j=(*i)-1; used.find(j)!=used.end(); j--)
			{
				used[j] = true;
				l++;
			}
			
			for (int j=(*i)+1; used.find(j)!=used.end(); j++)
			{
				used[j] = true;
				l++;
			}
			
			if (l > longest)
				longest = l;
		}
		return longest;
    }
};


int main()
{
	
	return 0;
}