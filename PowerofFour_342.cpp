/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 342. Power of Four
~ Link      : https://leetcode.com/problems/power-of-four/
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num & (num - 1)) == 0) && !(num & 0xAAAAAAAA);
    }
};
