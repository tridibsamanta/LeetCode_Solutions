/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 62. Unique Paths
~ Link      : https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:

    int dp[105][105];

    // ***** BOTTOM-UP (Tabulation) Approach *****/
    /*
    int uniquePaths(int m, int n) {

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= m; ++i)
            dp[i][1] = 1;
        for (int i = 0; i <= n; ++i)
            dp[1][i] = 1;

        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
    */

    // ***** TOP-DOWN (Memoization) Approach *****/

    int uniquePathsUtil(int m, int n) {

        if (m == 1 || n == 1)
            return 1;

        if (dp[m][n] != -1)
            return dp[m][n];

        return dp[m][n] = uniquePathsUtil(m - 1, n) + uniquePathsUtil(m, n - 1);
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return uniquePathsUtil(m, n);
    }

};
