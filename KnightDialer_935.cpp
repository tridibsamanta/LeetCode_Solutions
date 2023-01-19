/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 935. Knight Dialer
~ Link      : https://leetcode.com/problems/knight-dialer/
*/

/* Approach 1 (Top-Down / Memoization) */
/*
class Solution {
public:
    static const int MOD = 1000000007;

    unordered_map<int, vector<int> > adj =   {{0, {4, 6}},
                                              {1, {6, 8}},
                                              {2, {7, 9}},
                                              {3, {4, 8}},
                                              {4, {0, 3, 9}},
                                              {5, {}},
                                              {6, {0, 1, 7}},
                                              {7, {2, 6}},
                                              {8, {1, 3}},
                                              {9, {2, 4}}};

    int knightDialerUtil(int digit, int steps, vector<vector<int> > &dp) {
        if (steps == 0)
            return 1;

        if (dp[digit][steps] != -1)
            return dp[digit][steps];

        long cnt = 0;

        for (int i = 0; i < adj[digit].size(); ++i) {
            int nextDigit = adj[digit][i];

            cnt = (cnt + knightDialerUtil(nextDigit, steps - 1, dp)) % MOD;
        }

        return dp[digit][steps] = cnt;
    }


    int knightDialer(int n) {
        long res = 0;

        vector<vector<int> > dp(10, vector<int> (n, -1));

        for (int i = 0; i < 10; ++i) {
            res = (res + knightDialerUtil(i, n - 1, dp)) % MOD;
        }

        return res;
    }
};
*/
// Time Complexity - O(10 * n)
// Auxiliary Space - O(10 * n)

/* Approach 2 (Bottom-Up / Tabulation) */

class Solution {
public:
    static const int MOD = 1000000007;

    unordered_map<int, vector<int> > adj =   {{0, {4, 6}},
                                              {1, {6, 8}},
                                              {2, {7, 9}},
                                              {3, {4, 8}},
                                              {4, {0, 3, 9}},
                                              {5, {}},
                                              {6, {0, 1, 7}},
                                              {7, {2, 6}},
                                              {8, {1, 3}},
                                              {9, {2, 4}}};

    int knightDialer(int n) {
        vector<vector<long> > dp(n, vector<long> (10, 0));

        for (int digit = 0; digit < 10; ++digit) {
            dp[0][digit] = 1;
        }

        for (int steps = 1; steps < n; ++steps) {
            for (int digit = 0; digit < 10; ++digit) {

                for (int prevDigit : adj[digit]) {
                    dp[steps][digit] = (dp[steps][digit] + dp[steps - 1][prevDigit]) % MOD;
                }
            }
        }

        long res = 0;

        for (int digit = 0; digit < 10; ++digit) {
            res = (res + dp[n - 1][digit]) % MOD;
        }

        return res;
    }
};

// Time Complexity - O(n * 10)
// Auxiliary Space - O(n * 10)
