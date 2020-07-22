/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 283. Move Zeroes
~ Link      : https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                if (idx < i)
                    nums[i] = 0;
                ++idx;
            }
        }
    }
};
