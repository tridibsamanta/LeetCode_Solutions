/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 231. Power of Two
~ Link      : https://leetcode.com/problems/power-of-two/
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        return !(n & (n - 1));
    }
};
