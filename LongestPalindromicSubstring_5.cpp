/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 5. Longest Palindromic Substring
~ Link      : https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
    string longestPalindrome(string s) {

        string res;

        int n = s.length();

        if (!n)
            return res;

        bool dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        int startIdx = 0, maxLen = 1, flag = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])  {
                dp[i][i+1] = true;
                if (!flag) {
                    startIdx = i;
                    maxLen = 2;
                    ++flag;
                }
            }
        }

        for (int k = 3; k <= n; ++k) {

            for (int i = 0; i <= n - k; ++i) {

                int j = i + k - 1;

                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (k > maxLen) {
                        maxLen = k;
                        startIdx = i;
                    }
                }
            }
        }

        for (int i = startIdx; i < startIdx + maxLen; ++i)
            res += s[i];

        return res;

        }
};
