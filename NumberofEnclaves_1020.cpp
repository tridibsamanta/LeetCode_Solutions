/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1020. Number of Enclaves
~ Link      : https://leetcode.com/problems/number-of-enclaves/
*/

class Solution {
public:
    void dfs(int r, int c, vector<vector<int> > &grid) {
        grid[r][c] = 2;

        static int row4D[] = {-1, 0, 1, 0};
        static int col4D[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; ++k) {
            int adjR = r + row4D[k], adjC = c + col4D[k];

            if ((adjR >= 0 && adjR < grid.size()) &&
               (adjC >= 0 && adjC < grid[0].size()) &&
               grid[adjR][adjC] == 1) {
                dfs(adjR, adjC, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) &&
                    grid[i][j] == 1)
                    dfs(i, j, grid);
            }
        }

        int validCellCount = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                validCellCount += (grid[i][j] == 1);
            }
        }

        return validCellCount;
    }
};

// Time Complexity - O(r * c)
// Space Complexity - O(r * c)
