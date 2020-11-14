/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1143. Longest Common Subsequence
~ Link      : https://leetcode.com/problems/longest-common-subsequence/
*/

class Solution {
public:

    int dp[1005][1005];

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length(), n = text2.length();

        for (int i = 0; i < n + 1; ++i)
            dp[0][i] = 0;
        for (int i = 0; i < m + 1; ++i)
            dp[i][0] = 0;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};
