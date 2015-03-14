/*
 * Author	: ZhaoW
 * Time		: 2015-03-13 13:55:30
 * problem	: https://leetcode.com/problems/set-matrix-zeroes/
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
		if (row == 0)
			return ;
		int col = matrix[0].size();
		
		bool rowZero = false;
		bool colZero = false;
		
		for (int j=0; j<col && !rowZero;  j++)
		{
			if (matrix[0][j] == 0)
			    rowZero=true;
		}
		
		for (int j=0; j<row && !colZero;  j++)
		{
			if (matrix[j][0] == 0)
			    colZero=true;
		}
		
		for (int i=1; i<row; i++)
		{
			for (int j=1; j<col; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		
		for (int i=1; i<row; i++)
		{
			for (int j=1; j<col && matrix[i][0] == 0; j++)
			{
				matrix[i][j] = 0;
			}
		}
		
		for (int i=1; i<col; i++)
		{
			for (int j=1; j<row && matrix[0][i] == 0; j++)
			{
				matrix[j][i] = 0;
			}
		}
		
		
	    for (int j=0; rowZero && j<col;  j++)
		{
			matrix[0][j] = 0;
		}
		
		for (int j=0; colZero && j<row;  j++)
		{
			matrix[j][0] = 0;
		}
	
		return ;
    }
};

int main()
{
	return 0;
}
