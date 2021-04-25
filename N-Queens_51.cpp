/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 51. N-Queens
~ Link      : https://leetcode.com/problems/n-queens/
*/

class Solution {
public:
    bool col[11], diag1[21], diag2[21];
    vector<vector<string> > res;

    void solveNQueensUtil(int y, int n, vector<int>& curr){

        if (y == n) {
            vector<string> soln;
            for (auto i : curr) {
                string row = "";
                for (int j = 0; j < n; ++j) {
                    if (i == j)
                        row += 'Q';
                    else
                        row += '.';
                }
                soln.emplace_back(row);
            }
            res.emplace_back(soln);
            return;
        }

        for (int i = 0; i < n; ++i) {

            if (col[i] || diag1[i + y] || diag2[i - y + n - 1])
                continue;

            col[i] = diag1[i + y] = diag2[i - y + n - 1] = true;

            curr.emplace_back(i);

            solveNQueensUtil(y + 1, n, curr);

            // backtrack
            col[i] = diag1[i + y] = diag2[i - y + n - 1] = false;
            curr.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        memset(col, false, sizeof(col));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));

        vector<int> curr;

        solveNQueensUtil(0, n, curr);

        return res;
    }
};

// T.C. - O(n!)
// S.C. - O(n)
