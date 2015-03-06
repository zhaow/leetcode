/*
 * Author	: ZhaoW
 * Time		: 2015-03-05  09:05:26
 * problem	: https://oj.leetcode.com/problems/valid-number/
 Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
		string tmp = s;
		
		skipSpace(tmp);
		if (tmp.empty())
			return false;
		skipSign(tmp);
		if (tmp.empty())
			return false;
		
		if (!skipNum(tmp))
			return false;
			
		if (!tmp.empty() && (tmp.front() == 'e' || tmp.front() == 'E'))
		{	
			tmp.erase(tmp.begin());
			skipSign(tmp);
			if (tmp.empty())
				return false;
			if (!skipInt(tmp))
				return false;
		} 
		skipSpace(tmp);
		if (!tmp.empty())
		{
			return false;
		} 
		else
		{
			return true;
		}
    }
private:
	void skipSpace(string& s)
	{
		while(!s.empty() && s.front() == ' ')
		{
			s.erase(s.begin());
		}
	}
	
	void skipSign(string& s)
	{
		while(!s.empty() && (s.front()=='+' || s.front()=='-'))
		{
			s.erase(s.begin());
		}
	}
	
	bool skipNum(string& s)
	{
		bool tag = false;
		while(!s.empty() && (s.front()>='0' && s.front()<='9'))
		{
			tag = true;
			s.erase(s.begin());
		}
		if (s.front() == '.')
			s.erase(s.begin());
		while(!s.empty() && (s.front()>='0' && s.front()<='9'))
		{
			tag = true;
			s.erase(s.begin());
		}
		return tag;
	}
	
	bool skipInt(string& s)
	{
		bool tag = false;
		while(!s.empty() && (s.front()>='0' && s.front()<='9'))
		{
			tag = true;
			s.erase(s.begin());
		}
		return tag;
	}
};

int main()
{
	Solution myTest;
	string t;
	while(true)
	{
		cin >> t;
		cout << myTest.isNumber(t) << endl;
	}
	return 0;
}
