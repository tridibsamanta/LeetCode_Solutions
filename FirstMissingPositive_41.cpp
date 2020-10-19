/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 41. First Missing Positive
~ Link      : https://leetcode.com/problems/first-missing-positive/
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while ((nums[i] >= 1 && nums[i] <= n) && (nums[i] != nums[nums[i] - 1]))
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
