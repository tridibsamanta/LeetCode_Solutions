/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 268. Missing Number
~ Link      : https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int x1 = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            x1 ^= nums[i];

        int x2 = 0;
        for (int i = 1; i <= nums.size(); ++i)
            x2 ^= i;

        return (x1 ^ x2);
    }
};
