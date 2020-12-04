/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 807. Max Increase to Keep City Skyline
~ Link      : https://leetcode.com/problems/max-increase-to-keep-city-skyline/
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowMax(rows, INT_MIN);
        vector<int> colMax(cols, INT_MIN);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int ans = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }

        return ans;
    }
};
