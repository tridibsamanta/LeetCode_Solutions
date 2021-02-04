/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 213. House Robber II
~ Link      : https://leetcode.com/problems/house-robber-ii/
*/

// Bottom-Up (Tabulation) Approach - Using constant extra space

class Solution {
private:
    int robUtil(vector<int>& nums, int i, int n) {

        int prev1 = nums[i];
        int prev2 = max(nums[i], nums[i + 1]);

        for (int j = i + 2; j < n + 1; ++j) {
            int res = max(nums[j] + prev1, prev2);
            prev1 = prev2;
            prev2 = res;
        }

        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        return max(robUtil(nums, 0, n - 2), robUtil(nums, 1, n - 1));
    }
};

// T.C. - O(n)
// S.C. - O(1)

// Bottom-Up (Tabulation) Approach
/*
class Solution {
public:
    vector<int> dp;

    int robUtil(vector<int>& nums, int i, int n) {

        fill(dp.begin(), dp.end(), 0);

        dp[i + 1] = nums[i];
        dp[i + 2] = max(nums[i], nums[i + 1]);

        for (int j = i + 3; j <= n + 1; ++j) {
            dp[j] = max(nums[j - 1] + dp[j - 2], dp[j - 1]);
        }

        return dp[n + 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        dp.resize(n + 1);

        return max(robUtil(nums, 0, n - 2), robUtil(nums, 1, n - 1));
    }
};
*/
// T.C. - O(n)
// S.C. - O(n)
