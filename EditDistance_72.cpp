/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 72. Edit Distance
~ Link      : https://leetcode.com/problems/edit-distance/
*/

/* Bottom-Up Approach (Tabulation) */
class Solution {
public:
    vector<vector<int> > dp;

    int minDistance(string word1, string word2) {

        int len1 = word1.length();
        int len2 = word2.length();

        dp.resize(len1 + 1, vector<int> (len2 + 1));

        for (int i = 0; i <= len1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= len2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {

                int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;

                dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1,
                                                     dp[i - 1][j - 1] + cost));
            }
        }

        return dp[len1][len2];
    }
};

// T.C. - O(word1.length() * word2.length())
// S.C. - O(word1.length() * word2.length())

/* Top-Down Approach (Memoization) */
/*
class Solution {
public:
    vector<vector<int> > dp;

    int minDistanceUtil(int len1, int len2, string word1, string word2) {

        if (len1 == 0 && len2 == 0)
            return 0;

        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;

        if (dp[len1][len2] != -1)
            return dp[len1][len2];

        int cost;
        word1[len1 - 1] == word2[len2 - 1] ? cost = 0 : cost = 1;

        return dp[len1][len2] = min(minDistanceUtil(len1, len2 - 1, word1, word2) + 1,
                                    min(minDistanceUtil(len1 - 1, len2, word1, word2) + 1,
                                        minDistanceUtil(len1 - 1, len2 - 1, word1, word2) + cost));
    }

    int minDistance(string word1, string word2) {

        int len1 = word1.length();
        int len2 = word2.length();

        dp.resize(len1 + 1, vector<int> (len2 + 1, -1));

        return minDistanceUtil(len1, len2, word1, word2);
    }
};
*/
// T.C. - O(word1.length() * word2.length())
// S.C. - O(word1.length() * word2.length())
