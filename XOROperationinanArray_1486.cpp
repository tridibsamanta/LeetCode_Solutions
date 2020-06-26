/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1486. XOR Operation in an Array
~ Link      : https://leetcode.com/problems/xor-operation-in-an-array/
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = res ^ (start + 2 * i);
        return res;
    }
};
