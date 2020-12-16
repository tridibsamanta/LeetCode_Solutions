/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 509. Fibonacci Number
~ Link      : https://leetcode.com/problems/fibonacci-number/
*/

// Recursive Approach
/*
class Solution {
public:
    int fib(int n) {

        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};
*/

// TOP-DOWN Approach (Memoization)
/*
class Solution {
public:
    int dp[31];

    int fibo(int n) {

        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fibo(n - 1) + fibo(n - 2);
    }

    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        return fibo(n);
    }
};
*/

// BOTTOM-UP Approach (Tabulation)

class Solution {
public:
    int dp[31];

    int fib(int n) {

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
