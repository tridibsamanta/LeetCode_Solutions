/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 73. Set Matrix Zeroes
~ Link      : https://leetcode.com/problems/set-matrix-zeroes/
*/

// Approach 1: T.C. - O(r*c), S.C. - O(r + c)
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        bool row[r], col[c];

        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }

        for (int i = 0; i < r; ++i) {
            if (row[i]) {
                for (int j = 0; j < c; ++j)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < c; ++i) {
            if (col[i]) {
                for (int j = 0; j < r; ++j)
                    matrix[j][i] = 0;
            }
        }

    }
};
*/

// Approach 2: T.C. - O(r*c), S.C. - O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        bool isColZero = false; // To determine whether first column will be all 0's

        for (int i = 0; i < r; ++i) {

            if (matrix[i][0] == 0)
                isColZero = true;

            for (int j = 1; j < c; ++j) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int i = 0; i < c; ++i)
                matrix[0][i] = 0;
        }

        if (isColZero) {
            for (int i = 0; i < r; ++i)
                matrix[i][0] = 0;
        }
    }
};
