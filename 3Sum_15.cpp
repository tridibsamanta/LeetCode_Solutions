/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 15. 3Sum
~ Link      : https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int> > res;

        int n = nums.size();
        if (n < 3)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {

            int target = -nums[i];

            if (target < 0)
                break;

            int l = i + 1, r = n - 1;

            while (l < r) {

                int l_val = nums[l], r_val = nums[r];

                if (nums[l] + nums[r] == target) {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[l];
                    triplet[2] = nums[r];
                    res.emplace_back(triplet);

                    // Skip current duplicates
                    while (l < r && nums[l] == triplet[1])
                        ++l;
                    // Skip current duplicates
                    while (l < r && nums[r] == triplet[2])
                        --r;
                }
                else if (nums[l] + nums[r] < target) {
                    // Skip current duplicates
                    while (l < r && nums[l] == l_val)
                        ++l;
                }
                else {
                    // Skip current duplicates
                    while (l < r && nums[r] == r_val)
                        --r;
                }
            }

            // Skip current duplicates, keep in mind that for loop will also increment the value of i by 1
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }

        return res;
    }
};
