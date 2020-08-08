/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 200. Number of Islands
~ Link      : https://leetcode.com/problems/number-of-islands/
*/

class Solution {
private:
    bool isValidIdx(vector<vector<char>>& grid, int i, int j, vector<bool> visited[], int rows, int columns) {
        return (i >= 0) && (i < rows) && (j >= 0) && (j < columns) &&
            ((grid[i][j] == '1') && !visited[i][j]);
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<bool> visited[], int rows, int columns) {

        visited[i][j] = true;

        static int rowNum[] = {-1, 0, 0, 1};
        static int colNum[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; ++k) {
            if (isValidIdx(grid, i + rowNum[k], j + colNum[k], visited, rows, columns))
                dfs(grid, i + rowNum[k], j + colNum[k], visited, rows, columns);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.size() == 0)
            return 0;

        int rows = grid.size();
        int columns = grid[0].size();

        vector<bool> visited[rows];
        for (int i = 0; i < rows; ++i) {
            visited[i] = vector<bool> (columns);
            for (int j = 0; j < columns; ++j)
                visited[i][j] = false;
        }

        int islandCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if ((grid[i][j] == '1') && !visited[i][j]) {
                    dfs(grid, i, j, visited, rows, columns);
                    ++islandCount;
                }
            }
        }

        return islandCount;
    }
};
