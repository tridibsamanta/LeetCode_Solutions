/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 695. Max Area of Island
~ Link      : https://leetcode.com/problems/max-area-of-island/
*/

class Solution {
private:
    void dfsUtil(int i, int j, vector<vector<int>>& grid, int r, int c, int &currArea) {

        static int rowPos[] = {-1, 1, 0, 0};
        static int colPos[] = {0, 0, -1, 1};

        if ((i < 0 || i >= r) || (j < 0 || j >= c) ||
            grid[i][j] != 1)
            return;

        ++currArea;
        grid[i][j] = 9;

        for (int k = 0; k < 4; ++k)
            dfsUtil(i + rowPos[k], j + colPos[k], grid, r, c, currArea);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int r = grid.size();
        if (r == 0)
            return 0;

        int c = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    int currArea = 0;
                    dfsUtil(i, j, grid, r, c, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
