/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 322. Coin Change
~ Link      : https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {

            for (int j = 0; j < coins.size(); ++j) {

                if (coins[j] <= i && dp[i - coins[j]] != -1) {

                    if (dp[i] > 0)
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    else
                        dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        return dp[amount];
    }
};
