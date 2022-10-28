/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 542. 01 Matrix
~ Link      : https://leetcode.com/problems/01-matrix/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();

        vector<vector<int> > res(r, vector<int> (c, 0));
        vector<vector<bool> > visited(r, vector<bool> (c, false));

        queue<vector<int> > todo;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] == 0) {
                    todo.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        static int row4D[] = {-1, 0, 1, 0};
        static int col4D[] = {0, 1, 0, -1};

        while (!todo.empty()) {
            vector<int> curr = todo.front();
            todo.pop();

            for (int k = 0; k < 4; ++k) {
                int adj_r = curr[0] + row4D[k];
                int adj_c = curr[1] + col4D[k];

                if ((adj_r >= 0 && adj_r < r) && (adj_c >= 0 && adj_c < c) &&
                   !visited[adj_r][adj_c] && mat[adj_r][adj_c] == 1) {
                    res[adj_r][adj_c] = curr[2] + 1;
                    todo.push({adj_r, adj_c, res[adj_r][adj_c]});
                    visited[adj_r][adj_c] = true;
                }
            }
        }

        return res;
    }
};

// Time Complexity - O(r * c)
// Auxiliary Space - O(r * c)
