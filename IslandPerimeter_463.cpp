/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 463. Island Perimeter
~ Link      : https://leetcode.com/problems/island-perimeter/
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {

                if (grid[i][j] == 1) {

                    if (i == 0 || grid[i - 1][j] == 0)
                        ++perimeter;
                    if (j == 0 || grid[i][j - 1] == 0)
                        ++perimeter;
                    if (i == r - 1 || grid[i + 1][j] == 0)
                        ++perimeter;
                    if (j == c - 1 || grid[i][j + 1] == 0)
                        ++perimeter;
                }
            }
        }
        return perimeter;
    }
};
