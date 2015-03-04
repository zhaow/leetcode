/*
 * Author	: ZhaoW
 * Time		: 2015-03-04 18:14:15
 * problem	: https://oj.leetcode.com/problems/word-search/
  Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		int i, j, x, y;
		int step;
		
		for (i=0; i<board.size(); i++)
		{
			for (j=0; j<board[i].size(); j++)
			{
				if (board[i][j] == word[0])
				{
					x = i;
					y = j;
					step = 1;
					board[x][y] = '@';
					while(step<word.size())
					{
						if (x-1>=0 && board[x-1][y]==word[step])
						{
							board[x-1][y] = '@';
							x = x-1;
							step++;
						} else if (x+1<board.size() && board[x+1][y]==word[step])
						{
							board[x+1][y] = '@';
							x = x+1;
							step++;
						} else if (y-1>=0 && board[x][y-1]==word[step])
						{
							board[x][y-1] = '@';
							y = y-1;
							step++;
						} else if (y+1<board[x].size() && board[x][y+1]==word[step])
						{
							board[x][y+1] = '@';
							y = y+1;
							step++;
						} else 
						{
							break;
						}
					}
					if (step == word.size())
						return true;
				}
			}
		}
		return false;
    }
};


int main()
{
	Solution myTest;
	vector<vector<char> > t;
	vector<char> t1;
	t1.push_back('a');
	t1.push_back('b');
	t.push_back(t1);
	
	string a = "ba";
	
	cout << myTest.exist(t, a);
	cin >> a;
	cout << a;
	return 0;
}
