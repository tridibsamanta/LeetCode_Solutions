/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 746. Min Cost Climbing Stairs
~ Link      : https://leetcode.com/problems/min-cost-climbing-stairs/
*/

// Bottom-Up Approach (Tabulation)

class Solution {
public:
    int dp[1005];

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[n - 1], dp[n - 2]);
    }
};


// Bottom-Up Approach (Constant-Space)
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int first = cost[0], second = cost[1];

        for (int i = 2; i < cost.size(); ++i) {
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }

        return min(first, second);
    }
};
*/


// Top-Down Approach (Memoization)
/*
class Solution {
public:
    int dp[1005];

    int minCostClimbingStairsUtil(vector<int>& cost, int n) {

        if (n <= 2)
            return cost[n - 1];

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = cost[n - 1] + min(minCostClimbingStairsUtil(cost, n - 1), minCostClimbingStairsUtil(cost, n - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int n = cost.size();

        // We don't return dp[n] directly below,
        // as we can reach the top floor from dp[n] or dp[n - 1]
        minCostClimbingStairsUtil(cost, n);

        // Hence return minimum cost between dp[n] and dp[n - 1]
        return min(dp[n], dp[n-1]);
    }
};
*/
