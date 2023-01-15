/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 44. Wildcard Matching
~ Link      : https://leetcode.com/problems/wildcard-matching/
*/

/* Top-Down (Memoization) Approach */
/*
class Solution {
public:
    bool isMatchUtil(string s, int sIdx, string p, int pIdx,
                    vector<vector<int> > &dp) {

        if (sIdx < 0 && pIdx < 0)
            return true;
        if (sIdx >= 0 && pIdx < 0)
            return false;
        if (sIdx < 0 && pIdx >= 0) {
            for (int i = 0; i <= pIdx; ++i) {
                if (p[i] != '*')
                    return false;
            }

            return true;
        }

        if (dp[sIdx][pIdx] != -1)
            return dp[sIdx][pIdx];

        if (s[sIdx] == p[pIdx] || p[pIdx] == '?')
            return dp[sIdx][pIdx] = isMatchUtil(s, sIdx - 1, p, pIdx - 1, dp);

        if (p[pIdx] == '*')
            return dp[sIdx][pIdx] = isMatchUtil(s, sIdx - 1, p, pIdx, dp) || isMatchUtil(s, sIdx, p, pIdx - 1, dp);

        return dp[sIdx][pIdx] = false;
    }

    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();

        vector<vector<int> > dp(s_len, vector<int> (p_len, -1));

        return isMatchUtil(s, s_len - 1, p, p_len - 1, dp);
    }
};
*/
// Time Complexity - O(s.size() * p.size())
// Auxiliary Space - O(s.size() * p.size())

/* Bottom-Up (Tabulation) Approach */

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();

        vector<vector<bool> > dp(s_len + 1, vector<bool> (p_len + 1));

        // // string 's' is empty and string 'p' is empty
        dp[0][0] = true;

        // string 's' is non-empty but string 'p' is empty
        for (int i = 1; i < s_len + 1; ++i) {
            dp[i][0] = false;
        }

        // string 's' is empty but string 'p' is non-empty
        for (int j = 1; j < p_len + 1; ++j) {
            if (dp[0][j - 1] == true && p[j - 1] == '*')
                dp[0][j] = true;
            else
                dp[0][j] = false;
        }

        for (int i = 1; i < s_len + 1; ++i) {
            for (int j = 1; j < p_len + 1; ++j) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[s_len][p_len];
    }
};

// Time Complexity - O(s.size() * p.size())
// Auxiliary Space - O(s.size() * p.size())
