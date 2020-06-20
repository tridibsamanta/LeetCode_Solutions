/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 26. Remove Duplicates from Sorted Array
~ Link      : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int unique = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[unique]) {
                ++unique;
                nums[unique] = nums[i];
            }
        }
        return unique + 1;
    }
};
