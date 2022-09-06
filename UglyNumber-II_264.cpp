/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 264. Ugly Number II
~ Link      : https://leetcode.com/problems/ugly-number-ii/
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        vector<int> dp(n);
        dp[0] = 1;

        int twoPos = 0, threePos = 0, fivePos = 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = min({dp[twoPos] * 2, dp[threePos] * 3, dp[fivePos] * 5});

            if (dp[i] == dp[twoPos] * 2)
                ++twoPos;

            if (dp[i] == dp[threePos] * 3)
                ++threePos;

            if (dp[i] == dp[fivePos] * 5)
                ++fivePos;
        }

        return dp[n - 1];
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
