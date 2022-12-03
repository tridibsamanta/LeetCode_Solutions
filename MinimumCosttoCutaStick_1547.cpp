/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1547. Minimum Cost to Cut a Stick
~ Link      : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

/* Approach 1 : Top-Down (Memoization) */
/*
class Solution {
public:
    int minCostUtil(vector<int> &cuts, int l, int r, vector<vector<int> > &dp) {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int minCost = INT_MAX;

        for (int i = l; i <= r; ++i) {
            int currCost = cuts[r + 1] - cuts[l - 1] +
                            minCostUtil(cuts, l, i - 1, dp) +
                            minCostUtil(cuts, i + 1, r, dp);

            minCost = min(minCost, currCost);
        }

        return dp[l][r] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.emplace_back(n);

        vector<vector<int> > dp(c + 1, vector<int> (c + 1, -1));

        return minCostUtil(cuts, 1, c, dp);
    }
};
*/
// Time Complexity - O(c^3)
// Auxiliary Space - O(c^2)

/* Approach 2 : Bottom-Up (Tabulation) */

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.emplace_back(n);

        vector<vector<int> > dp(c + 2, vector<int> (c + 2, 0));

        for (int i = c; i >= 1; --i) {
            for (int j = 1; j <= c; ++j) {

                if (i > j)
                    continue;

                int minCost = INT_MAX;

                for (int k = i; k <= j; ++k) {
                    int currCost = cuts[j + 1] - cuts[i - 1] +
                                dp[i][k - 1] + dp[k + 1][j];

                    minCost = min(minCost, currCost);
                }

                dp[i][j] = minCost;
            }
        }

        return dp[1][c];
    }
};

// Time Complexity - O(c^3)
// Auxiliary Space - O(c^2)
