/*
 * Author	: ZhaoW
 * Time		: 2015-03-12 15:08:38
 * problem	: https://leetcode.com/problems/gray-code/
 The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
/*better solution
 * vector<int> grayCode(int n) {
	vector<int> result;
	result.reserve(1<<n);
	result.push_back(0);
	for (int i = 0; i < n; i++) {
	const int highest_bit = 1 << i;
	for (int j = result.size() - 1; j >= 0; j--) // 要反着遍历,才能对称
	result.push_back(highest_bit | result[j]);
	}
	return result;
	}
* */

    vector<int> grayCode(int n) {
		string code;
		ans.clear();
		table.clear();
		
		cnt = 1;
        for (int i=0; i<n; i++)
		{
			code.push_back(0);
		}
		
		ans.push_back(0);
		table.insert(make_pair(0, code));
		
		fun(code, n);
		
		return ans;
    }
private:
	int cnt;
	vector<int> ans;
	unordered_map<int , string> table;
	typedef unordered_map<int , string>::iterator ITE;
	int b2d(const string& a)
	{
		int ans = 0;
		for (int i=0; i<a.size(); i++)
		{
			ans = ans * 2 + a[i]; 
		}
		return ans; 
	}
	
	bool fun(string &code, int n)
	{
		int size = ans.size();
		
		if (cnt == pow(2, n))
		{
			if (size == cnt)
				return true;
			else
				return false;
		}
		
		for (int j=code.size()-1; j>=0; j--)
		{
			code[j] = (!code[j]);
			int tmp = b2d(code);
			if (table.find(tmp) == table.end())
			{
				ans.push_back(tmp);
				pair<ITE, bool> ite = table.insert(make_pair(tmp, code));
				cnt++;
				if (!fun(code, n)) {
					cnt--;
					ans.pop_back();
					table.erase(ite.first);
				} else {
					return true;
				}
			} else {
				code[j] = (!code[j]);
			}
		}
	}
};

int main()
{
	Solution myTest;
	int n;
	vector<int> ans;
	while (true)
	{
		cin >> n;
		ans = myTest.grayCode(n);
		
		for(int i=0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}