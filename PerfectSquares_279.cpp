/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 279. Perfect Squares
~ Link      : https://leetcode.com/problems/perfect-squares/
*/

class Solution {
public:
    int numSquares(int n) {

        if (n <= 0)
            return 0;

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        /*
            We need to represent 'i' as (i - (j*j)) + (j*j)
            eg. 5 = 1 + 4, where i=5, j=2
            Also, j is maximised such that j * j <= i
        */

        for (int i = 1; i <= n; ++i) {

            for (int j = 1; j * j <= i; ++j) {

                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }

        return dp[n];
    }
};

// T.C. - O(n * sqrt(n))
// S.C. - O(n)
