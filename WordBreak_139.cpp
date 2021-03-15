/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 139. Word Break
~ Link      : https://leetcode.com/problems/word-break/
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (dp[j] == true && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// T.C. - O(s.length^2 * wordDict.length)
// S.C. - O(s.length)
