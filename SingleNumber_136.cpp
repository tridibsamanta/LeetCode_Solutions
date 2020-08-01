/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 136. Single Number
~ Link      : https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int dup;
        for (int i = 0; i < nums.size(); ++i)
            dup ^= nums[i];
        return dup;
    }
};
