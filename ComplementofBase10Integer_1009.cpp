/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1009. Complement of Base 10 Integer
~ Link      : https://leetcode.com/problems/complement-of-base-10-integer/
*/

class Solution {
public:
    int bitwiseComplement(int N) {

        if (N == 0)
            return 1;

        long mask = 1;
        while (mask <= N)
            mask = mask << 1;
        return N ^ (mask - 1);
    }
};
