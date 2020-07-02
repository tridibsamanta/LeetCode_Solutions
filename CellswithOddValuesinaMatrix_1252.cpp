/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1252. Cells with Odd Values in a Matrix
~ Link      : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
*/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {

        int odds = 0;

        vector<bool> rows(n, false), cols(m, false);

        for(auto vec : indices) {
            rows[vec[0]] = !rows[vec[0]];
            cols[vec[1]] = !cols[vec[1]];
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(rows[i] ^ cols[j])
                    ++odds;
            }
        }
        return odds;
    }
};
