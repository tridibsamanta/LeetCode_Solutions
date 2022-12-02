/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 312. Burst Balloons
~ Link      : https://leetcode.com/problems/burst-balloons/
*/

/* Approach 1 : Top-Down (Memoization) */
/*
class Solution {
public:
    int maxCoinsUtil(vector<int> &nums, int l, int r, vector<vector<int> > &dp) {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int maxCost = 0;

        for (int i = l; i <= r; ++i) {
            int currCost = (nums[l - 1] * nums[i] * nums[r + 1]) +
                maxCoinsUtil(nums, l, i - 1, dp) + maxCoinsUtil(nums, i + 1, r, dp);

            maxCost = max(maxCost, currCost);
        }

        return dp[l][r] = maxCost;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);

        vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));

        return maxCoinsUtil(nums, 1, n, dp);
    }
};
*/
// Time Complexity - O(n^3)
// Auxiliary Space - O(n^2)

/* Approach 2 : Bottom-Up (Tabulation) */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);

        vector<vector<int> > dp(n + 2, vector<int> (n + 2, 0));

        for (int i = n; i >= 1; --i) {
            for (int j = 1; j <= n; ++j) {

                if (i > j)
                    continue;

                int maxCost = 0;

                for (int idx = i; idx <= j; ++idx) {
                    int currCost = (nums[i - 1] * nums[idx] * nums[j + 1]) +
                                    dp[i][idx - 1] + dp[idx + 1][j];

                    maxCost = max(maxCost, currCost);
                }

                dp[i][j] = maxCost;
            }
        }

        return dp[1][n];
    }
};

// Time Complexity - O(n^3)
// Auxiliary Space - O(n^2)
