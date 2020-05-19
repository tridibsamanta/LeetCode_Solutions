/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 191. Number of 1 Bits
~ Link      : https://leetcode.com/problems/number-of-1-bits/
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            ++count;
        }
        return count;
    }
};
