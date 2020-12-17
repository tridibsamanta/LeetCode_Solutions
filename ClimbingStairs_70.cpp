/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 70. Climbing Stairs
~ Link      : https://leetcode.com/problems/climbing-stairs/
*/

// Top-Down Approach (Memoization)
/*
class Solution {
public:
    int dp[50];

    int climbStairsUtil(int n) {

        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = climbStairsUtil(n - 1) + climbStairsUtil(n - 2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return climbStairsUtil(n);
    }
};
*/

// Bottom-Up Approach (Tabulation)
/*
class Solution {
public:
    int dp[50];

    int climbStairs(int n) {

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
*/

// Bottom-Up Approach (Without using dp array, O(1) space)

class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2)
            return n;

        int first = 1, second = 2, res = 0;

        for (int i = 3; i <= n; ++i) {
            res = first + second;
            first = second;
            second = res;
        }

        return res;
    }
};
