/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 188. Best Time to Buy and Sell Stock IV
~ Link      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

// Approach 1
/*
class Solution {
public:
    int dp[101][1001];

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        if (n <= 0 || k <= 0)
            return 0;

        for (int i = 1; i <= k; ++i) {

            for (int j = 1; j < n; ++j) {

                int maxVal = 0;

                for (int m = 0; m < j; ++m)
                     maxVal = max(maxVal, prices[j] - prices[m] + dp[i-1][m]);


                dp[i][j] = max(dp[i][j-1], maxVal);
            }
        }

        return dp[k][n-1];
    }
};
*/
// T.C. - O(K * N^2)
// S.C. - O(K * N)


// Approach 2 (Efficient)

class Solution {
public:
    int dp[101][1001];

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        if (n <= 0 || k <= 0)
            return 0;

        for (int i = 1; i <= k; ++i) {

            int maxDiff = -prices[0];

            for (int j = 1; j < n; ++j) {

                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);

                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }

        return dp[k][n-1];
    }
};

// T.C. - O(K * N)
// S.C. - O(K * N)
