/*
 * Author	: ZhaoW
 * Time		: 2015-03-25 15:45:42
 * problem	: https://leetcode.com/problems/number-of-1-bits/
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;
        while (n != 0) {
            ++count;
            n &= (n-1);
        }
        return count;
    }
};

int main()
{
	return 0;
}
