/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 172. Factorial Trailing Zeroes
~ Link      : https://leetcode.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {

        long long i = 5, count = 0;

        while (n / i >= 1) {

            count += n / i;
            i *= 5;

        }

        return count;
    }
};
