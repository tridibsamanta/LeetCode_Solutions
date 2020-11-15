/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1092. Shortest Common Supersequence
~ Link      : https://leetcode.com/problems/shortest-common-supersequence/
*/

class Solution {
public:

    int dp[1001][1001];

    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.length(), n = str2.length();

        for (int i = 0; i < n + 1; ++i)
            dp[0][i] = 0;
        for (int i = 0; i < m + 1; ++i)
            dp[i][0] = 0;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        string scs = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
                --j;
            }
            else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    scs.push_back(str2[j - 1]);
                    --j;
                }
                else {
                    scs.push_back(str1[i - 1]);
                    --i;
                }
            }
        }

        while (i > 0) {
            scs.push_back(str1[i - 1]);
            --i;
        }

        while (j > 0) {
            scs.push_back(str2[j - 1]);
            --j;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};
