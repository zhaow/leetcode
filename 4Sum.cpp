/*
 * Author	: ZhaoW
 * Time		: 2015-03-11 14:00:26
 * problem	: https://leetcode.com/problems/4sum/
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        for (int fst = 0; fst < num.size(); ++fst) {
            for (int snd = fst + 1; snd < num.size(); ++snd) {
                int thd = snd + 1, fth = num.size() - 1;
                while (thd < fth) {
                    int sum = num[fst] + num[snd] + num[thd] + num[fth];
                    if (sum == target) {
                        int tmp[4] = {num[fst], num[snd], num[thd], num[fth]};
                        ret.push_back(vector<int>(tmp, tmp + 4));
                        while (thd < num.size() - 1 && num[thd + 1] == num[thd]) {
                            ++thd;
                        }
                        while (fth > thd && num[fth - 1] == num[fth]) {
                            --fth;
                        }
                        ++thd;
                        --fth;
                    }
                    else if (sum < target) {
                        ++thd;
                    }
                    else {
                        --fth;
                    }
                }
                while (snd < num.size() - 1 && num[snd + 1] == num[snd]) {
                    ++snd;
                }
            }
            while (fst < num.size() - 1 && num[fst + 1] == num[fst]) {
                ++fst;
            }
        }
        return ret;
    }

	/*TLE
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		
		if (num.size() < 4)
			return res;
			
		unordered_multimap<int, pair<int, int> > cache;
		
		for (auto i=num.begin(); i!=num.end()-1; i++)
		{
			for (auto j = i+1; j!=num.end(); j++)
			{
				cache.insert(make_pair( (*i)+(*j), make_pair((*i), (*j)) ));
			}
		}
		
		for (auto i=cache.begin(); i!=cache.end(); i++)
		{
			int need = target - (i->first);
			
			auto tmp = cache.equal_range(need);
			
			for (auto j = tmp.first; j != tmp.second; j++)
			{
				int a = i->second.first;
				int b = i->second.second;
				int c = j->second.first;
				int d = j->second.second;
				
				if (a != c && a != d && b!=c && b!=d)
				{
					vector<int> quarter = {a, b, c, d};
					sort(quarter.begin(), quarter.end());
					res.push_back(quarter);
				}
			}
		}
		
		sort(res.begin(), res.end());
		res.erase((unique(res.begin(), res.end())), res.end());
		
		return res;
	}
	 * */
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
		myTest.fourSum(A, 0);
	}
	
	return 0;
}

