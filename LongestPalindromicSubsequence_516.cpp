/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 516. Longest Palindromic Subsequence
~ Link      : https://leetcode.com/problems/longest-palindromic-subsequence/
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();

        if (!n)
            return 0;

        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {

            for (int i = 0; i <= n - len; ++i) {

                int j = i + len - 1;

                if (s[i] == s[j] && len == 2)
                    dp[i][j] = 2;
                else if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
