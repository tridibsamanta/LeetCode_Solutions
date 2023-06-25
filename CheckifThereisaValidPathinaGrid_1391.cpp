/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1391. Check if There is a Valid Path in a Grid
~ Link      : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
*/

class Solution {
public:
    bool hasValidPathUtil(char cellEntryDir, vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int r = m - 1, c = n - 1;

        while ((r >= 0 && r < m) && (c >= 0 && c < n)) {
            if (cellEntryDir == 'L') {
                if (--c < 0)
                    return false;

                if (grid[r][c] == 1)
                    cellEntryDir = 'L';
                else if (grid[r][c] == 4)
                    cellEntryDir = 'D';
                else if (grid[r][c] == 6)
                    cellEntryDir = 'U';
                else
                    return false;
            }
            else if (cellEntryDir == 'U') {
                if (--r < 0)
                    return false;

                if (grid[r][c] == 2)
                    cellEntryDir = 'U';
                else if (grid[r][c] == 3)
                    cellEntryDir = 'L';
                else if (grid[r][c] == 4)
                    cellEntryDir = 'R';
                else
                    return false;
            }
            else if (cellEntryDir == 'R') {
                if (++c >= n)
                    return false;

                if (grid[r][c] == 1)
                    cellEntryDir = 'R';
                else if (grid[r][c] == 3)
                    cellEntryDir = 'D';
                else if (grid[r][c] == 5)
                    cellEntryDir = 'U';
                else
                    return false;
            }
            else if (cellEntryDir == 'D') {
                if (++r >= m)
                    return false;

                if (grid[r][c] == 2)
                    cellEntryDir = 'D';
                else if (grid[r][c] == 5)
                    cellEntryDir = 'L';
                else if (grid[r][c] == 6)
                    cellEntryDir = 'R';
                else
                    return false;
            }

            if (r == 0 && c == 0)
            	return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (m == 1 && n == 1)
            return true;

        // L -> Left, U -> Up, R -> Right, D -> Down
        if (grid[m - 1][n - 1] == 1)
            return hasValidPathUtil('L', grid);
        else if (grid[m - 1][n - 1] == 2)
            return hasValidPathUtil('U', grid);
        else if (grid[m - 1][n - 1] == 3)
            return hasValidPathUtil('L', grid);
        else if (grid[m - 1][n - 1] == 5)
            return hasValidPathUtil('L', grid) || hasValidPathUtil('U', grid);
        else if (grid[m - 1][n - 1] == 6)
            return hasValidPathUtil('U', grid);

        return false;
    }
};

// Time Complexity - O(m * n)
// Space Complexity - O(1)
