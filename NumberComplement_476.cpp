/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 476. Number Complement
~ Link      : https://leetcode.com/problems/number-complement/
*/

class Solution {
public:
    int findComplement(int num) {

        long mask = 1;
        while (mask <= num)
            mask = mask << 1;

        return num ^ (mask - 1);
    }
};
