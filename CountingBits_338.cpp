/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 338. Counting Bits
~ Link      : https://leetcode.com/problems/counting-bits/
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cBits(num + 1, 0);
        //cBits[0] = 0;
        int offset = 1;
        for (int i = 1; i <= num; ++i) {
            if (offset * 2 == i)
                offset *= 2;
            cBits[i] = cBits[i - offset] + 1;
        }
        return cBits;
    }
};
