/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 673. Number of Longest Increasing Subsequence
~ Link      : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        if (n <= 1)
            return n;

        vector<int> dp(n, 1), counts(n, 1);

        int maxLen = 1;

        for (int i = 1; i < n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (nums[i] > nums[j]) {

                    if (dp[j] >= dp[i]) {
                        dp[i] = dp[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        counts[i] += counts[j];
                    }

                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen)
                cnt += counts[i];
        }

        return cnt;
    }
};

// T.C. - O(n^2)
// S.C. - O(n)
