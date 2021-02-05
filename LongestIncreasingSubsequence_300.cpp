/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 300. Longest Increasing Subsequence
~ Link      : https://leetcode.com/problems/longest-increasing-subsequence/
*/

// Top-Down (Memoization) Approach
/*
class Solution {
public:

    int dp[2501][2501];

    int lengthOfLISUtil(vector<int>& nums, int prev_idx, int curr_idx) {

        if (curr_idx == nums.size())
            return 0;

        if (dp[prev_idx + 1][curr_idx] != -1)
            return dp[prev_idx + 1][curr_idx];

        if (prev_idx < 0 || nums[curr_idx] > nums[prev_idx]) {
            return dp[prev_idx + 1][curr_idx] = max(1 + lengthOfLISUtil(nums, curr_idx, curr_idx + 1),
                                                    lengthOfLISUtil(nums, prev_idx, curr_idx + 1));
        }
        else {
            return dp[prev_idx + 1][curr_idx] = lengthOfLISUtil(nums, prev_idx, curr_idx + 1);
        }
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 1;

        memset(dp, -1, sizeof(dp));

        return lengthOfLISUtil(nums, -1, 0);
    }
};
*/
// T.C. - O(n^2)
// S.C. - O(n^2)

// Bottom-Up (Tabulation) Approach
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 1;

        vector<int> dp(n);

        dp[0] = 1;

        int maxLen = 1;

        for (int i = 1; i < n; ++i) {

            int currLen = 0;

            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    currLen = max(currLen, dp[j]);
                }
            }

            dp[i] = currLen + 1;

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
*/
// T.C. - O(n^2)
// S.C. - O(n)

// Using DP and Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp;

        dp.emplace_back(nums[0]);

        for (int i = 1; i < n; ++i) {

            auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);

            if (itr == dp.end())
                dp.emplace_back(nums[i]);
            else
                *itr = nums[i];
        }

        return dp.size();
    }
};

// T.C. - O(nlogn)
// S.C. - O(n)
