/*
 * Author	: ZhaoW
 * Time		: 2015-03-12 14:39:46
 * problem	: https://leetcode.com/problems/rotate-image/
 You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		if (matrix.empty() || matrix[0].size()==0)
			return ;
        auto size = matrix[0].size();
		
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size-i; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[size-j-1][size-i-1] ;
				matrix[size-j-1][size-i-1] = tmp;
			}
		}
		
		for (int i=0; i<size/2; i++)
		{
			for (int j=0; j<size; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[size-1-i][j];
				matrix[size-1-i][j] = tmp;
			}
		}
		
		return;
    }
};

int main()
{
	return 0;
}
