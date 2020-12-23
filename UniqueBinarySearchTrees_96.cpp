/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 96. Unique Binary Search Trees
~ Link      : https://leetcode.com/problems/unique-binary-search-trees/
*/

// Top-Down Approach

class Solution {
public:
    int dp[20];

    int numTreesUtil(int n) {

        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int res = 0;

        for (int i = 0; i < n; ++i)
            res += numTreesUtil(i) * numTreesUtil(n - i - 1);

        return dp[n] = res;
    }

    int numTrees(int n) {
        fill(dp, dp + 20, -1);
        return numTreesUtil(n);
    }
};

// Bottom-Up Approach
/*
class Solution {
public:
    int dp[20];

    int numTrees(int n) {

        fill(dp, dp + 20, 0);

        dp[0] = dp[1] = 1;

        for (int i = 2; i < n + 1; ++i) {

            for (int j = 0; j < i; ++j) {

                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
*/
