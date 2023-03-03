/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 64. Minimum Path Sum
~ Link      : https://leetcode.com/problems/minimum-path-sum/
*/

/* Top-Down Approach (Memoization) */
/*
class Solution {
public:
    vector<vector<int> > dp;

    int minPathSumUtil(int row, int col, vector<vector<int>>& grid) {
        if (row == 0 && col == 0)
            return grid[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int downSum = INT_MAX, rightSum = INT_MAX;

        if (row > 0)
            downSum = grid[row][col] + minPathSumUtil(row - 1, col, grid);

        if (col > 0)
            rightSum = grid[row][col] + minPathSumUtil(row, col - 1, grid);

        return dp[row][col] = min(downSum, rightSum);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        dp.resize(row, vector<int> (col, -1));

        return minPathSumUtil(row - 1, col - 1, grid);
    }
};
*/
// Time Complexity - O(row * col)
// Space Complexity - O(row * col)

/* Bottom-Up Approach (Tabulation) */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int> > dp(row, vector<int> (col));
        dp[0][0] = grid[0][0];

        // All cells in the first row (except grid[0][0])
        // can be reached only from the cell on the left of it.
        for (int i = 1; i < col; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        // All cells in the first column (except grid[0][0])
        // can be reached only from the cell on the top of it.
        for (int i = 1; i < row; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        // Remaining cells can be reached either from the cell
        // on its top or from the cell on its left
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[row - 1][col - 1];
    }
};

// Time Complexity - O(row * col)
// Space Complexity - O(row * col)
