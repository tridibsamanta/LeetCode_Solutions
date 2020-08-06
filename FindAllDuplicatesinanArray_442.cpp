/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 442. Find All Duplicates in an Array
~ Link      : https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> duplicates;

        if (!nums.size())
            return duplicates;

        for (int i = 0; i < nums.size(); ++i) {

            if (nums[abs(nums[i]) - 1] < 0)
                duplicates.emplace_back(abs(nums[i]));

            nums[abs(nums[i]) - 1] *= -1;
        }
        return duplicates;
    }
};
