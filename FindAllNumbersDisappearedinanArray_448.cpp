/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 448. Find All Numbers Disappeared in an Array
~ Link      : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> missing;
        if (!nums.size())
            return missing;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                missing.emplace_back(i + 1);
        }
        return missing;
    }
};
