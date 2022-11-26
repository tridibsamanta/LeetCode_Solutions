/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1091. Shortest Path in Binary Matrix
~ Link      : https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
            return -1;

        static int row8D[] = { -1, -1, -1, 0, 0, 1, 1, 1};
        static int col8D[] = { -1, 0, 1, -1, 1, -1, 0, 1};

        int shortestClearPathLen = -1;
        queue<vector<int> > todo; // {rowIndex, colIndex, pathLen}

        // start from the top-left cell
        todo.push({0, 0, 1});

        while (!todo.empty()) {
            auto curr = todo.front();
            todo.pop();

            // reached the bottom-right cell
            if ((curr[0] == row - 1) && (curr[1] == col - 1)) {
                shortestClearPathLen = curr[2];
                break;
            }

            for (int i = 0; i < 8; ++i) {
                int adjRow = curr[0] + row8D[i];
                int adjCol = curr[1] + col8D[i];

                if ((adjRow >= 0 && adjRow < row) && (adjCol >= 0 && adjCol < col)
                    && grid[adjRow][adjCol] == 0) {

                    todo.push({adjRow, adjCol, curr[2] + 1});

                    grid[adjRow][adjCol] = 1; // avoid re-visiting
                }
            }
        }

        return shortestClearPathLen;
    }
};

// Time Complexity - O(row * col)
// Auxiliary Space - O(row * col)
