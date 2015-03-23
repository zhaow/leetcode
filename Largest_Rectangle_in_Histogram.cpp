/*
 * Author	: ZhaoW
 * Time		: 2015-03-22 11:10:42
 * problem	: https://leetcode.com/problems/largest-rectangle-in-histogram/
  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		typedef pair<int , int> HS;
		typedef vector<HS>::iterator HSP;
		vector<HS> cache;
		
		int ans = 0;
		for (int i=0; i<height.size(); i++)
		{
			HS b;
			int sta = i;
			while (!cache.empty()) 
			{
				 b = cache.back();
				 if (b.first > height[i])
				 {
					sta = b.second;
					int S = b.first * (i - b.second);
					if (S > ans)
						 ans = S;
					cache.pop_back();
				 }
				 else
				 {
					break;
				 }
			}
			
			HS tmp = make_pair(height[i], sta);
			cache.push_back(tmp);
		}
		
		int size = height.size();
		for (HSP p = cache.begin(); p!=cache.end(); p++)
		{
			int S = p->first * (size - p->second);
			if (S > ans)
				ans = S;
		}
		
		return ans;
    }
};

int main()
{
	Solution myTest;
	vector<int> t;
	while (true)
	{
		t.clear();
		int size;
		cin >> size;
		while (--size)
		{
			int tmp;
			cin >> tmp;
			t.push_back(tmp);
		}
		cout << myTest.largestRectangleArea(t) << endl;
	}
	
	return 0;
}
