/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 813. Largest Sum of Averages
~ Link      : https://leetcode.com/problems/largest-sum-of-averages/
*/

class Solution {
public:
    double largestSumOfAveragesUtil(int idx, int k, vector<int>& nums,
                                   vector<vector<double> > &dp) {
        if (idx == nums.size() && k == 0)
            return 0;

        if (idx == nums.size() || k == 0)
            return INT_MIN;

        if (dp[idx][k] != -1.0)
            return dp[idx][k];

        double currAverage, currSum = 0;
        double maxScore = INT_MIN;

        for (int i = idx; i < nums.size(); ++i) {
            currSum += nums[i];
            currAverage = currSum / (double)(i - idx + 1);

            double currScore = largestSumOfAveragesUtil(i + 1, k - 1, nums, dp);

            if (currScore != INT_MIN)
                maxScore = max(maxScore, currAverage + currScore);
        }

        return dp[idx][k] = maxScore;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double> > dp(nums.size(), vector<double> (k + 1, -1.0));

        return largestSumOfAveragesUtil(0, k, nums, dp);
    }
};

// Time Complexity - O(n * n * k)
// Auxiliary Space - O(n * k)
