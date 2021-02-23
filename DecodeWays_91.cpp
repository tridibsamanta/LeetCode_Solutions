/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 91. Decode Ways
~ Link      : https://leetcode.com/problems/decode-ways/
*/

/* Bottom-Up Approach (Tabulation) */

class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        if (n == 0 || s[0] == '0')
            return 0;

        if (n == 1)
            return 1;

        int dp[n+1];

        memset(dp, 0, sizeof(dp));

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i) {

            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));

            if (oneDigit >= 1) {
                dp[i] = dp[i - 1];
            }

            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

// T.C. - O(n)
// S.C. - O(n)

/* Bottom-Up Approach (Without using extra space) */
/*
class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        if (n == 0 || s[0] == '0')
            return 0;

        if (n == 1)
            return 1;

        int prev1 = 1, prev2 = 1, ways;

        for (int i = 1; i < n; ++i) {

            ways = 0;

            int oneDigit = s[i] - '0';
            int twoDigit = stoi(s.substr(i - 1, 2));

            if (oneDigit >= 1) {
                ways = prev1;
            }

            if (twoDigit >= 10 && twoDigit <= 26) {
                ways += prev2;
            }

            prev2 = prev1;
            prev1 = ways;
        }

        return ways;
    }
};
*/
// T.C. - O(n)
// S.C. - O(1)
