/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1335. Minimum Difficulty of a Job Schedule
~ Link      : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/

class Solution {
public:
    int minDifficultyUtil(int daysLeft, int jobIdx, vector<int> &jobDifficulty,
                         vector<vector<int> > &dp) {

        if (daysLeft == 0 && jobIdx == jobDifficulty.size())
            return 0;

        if (daysLeft == 0 || jobIdx == jobDifficulty.size())
            return INT_MAX;

        if (dp[jobIdx][daysLeft] != -1)
            return dp[jobIdx][daysLeft];

        int currDayDifficulty = 0, maxDifficulty = INT_MAX;

        for (int i = jobIdx; i < jobDifficulty.size(); ++i) {
            currDayDifficulty = max(currDayDifficulty, jobDifficulty[i]);

            int remDayDifficulty = minDifficultyUtil(daysLeft - 1, i + 1, jobDifficulty, dp);

            if (remDayDifficulty != INT_MAX)
                maxDifficulty = min(maxDifficulty, currDayDifficulty + remDayDifficulty);
        }

        return dp[jobIdx][daysLeft] = maxDifficulty;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (d > n)
            return -1;

        vector<vector<int> > dp(n, vector<int> (d + 1, -1));

        return minDifficultyUtil(d, 0, jobDifficulty, dp);
    }
};

// Time Complexity - O(n * n * d)
// Auxiliary Space - O(n * d)
