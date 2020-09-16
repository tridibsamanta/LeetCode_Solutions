/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 18. 4Sum
~ Link      : https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int> > res;

        if (nums.empty())
            return res;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {

                int rem_target = target - (nums[i] + nums[j]);

                int l = j + 1, r = n - 1;

                while (l < r) {

                    int two_sum = nums[l] + nums[r];

                    if (two_sum < rem_target)
                        ++l;
                    else if (two_sum > rem_target)
                        --r;
                    else {
                        vector<int> quadruplet(4);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[l];
                        quadruplet[3] = nums[r];
                        res.emplace_back(quadruplet);

                        while (l < r && nums[l] == quadruplet[2])
                            ++l;

                        while (l < r && nums[r] == quadruplet[3])
                            --r;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;

            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
