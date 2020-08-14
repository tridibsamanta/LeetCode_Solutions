/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 994. Rotting Oranges
~ Link      : https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        static int rPos[] = {-1, 1, 0, 0};
        static int cPos[] = {0, 0, -1, 1};

        int r = grid.size(), c = grid[0].size();

        queue<pair<int, int> > q;

        int fresh_count = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if (grid[i][j] == 1)
                    ++fresh_count;
            }
        }

        if (fresh_count == 0)
            return 0;

        if (q.empty())
            return -1;

        int time = 0;
        while (!q.empty()) {

            ++time;
            int elements = q.size();

            for (int i = 0; i < elements; ++i) {

                pair<int, int> curr = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {

                    int adjR = curr.first + rPos[k];
                    int adjC = curr.second + cPos[k];

                    if ((adjR >= 0 && adjR < r) && (adjC >= 0 && adjC < c) &&
                        grid[adjR][adjC] == 1) {

                        q.push(make_pair(adjR, adjC));
                        grid[adjR][adjC] = 2;
                        --fresh_count;
                    }
                }
            }
        }

        return (fresh_count > 0) ? -1 : --time;
    }
};
