/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 74. Search a 2D Matrix
~ Link      : https://leetcode.com/problems/search-a-2d-matrix/
*/

// Brute-force Approach - T.C.: O(m*n)
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();

        if (r == 0)
            return false;

        int c = matrix[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
};
*/

// Efficient Approach - T.C.: O(m + n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0)
            return false;

        int r = matrix.size();
        int c = matrix[0].size();

        int rIdx = 0, cIdx = c - 1;

        while (rIdx < r && cIdx >= 0) {

            if (matrix[rIdx][cIdx] == target)
                return true;

            if (target > matrix[rIdx][cIdx])
                ++rIdx;
            else
                --cIdx;
        }
        return false;
    }
};

// Best Approach - T.C.: O(m + log n),
// could be easily tweaked to O(log m + log n)
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int r = matrix.size();
        int c = matrix[0].size();

        int target_row = -1;
        for (int i = 0; i < r; ++i) {

            if (target <= matrix[i][c - 1]) {
                target_row = i;
                break;
            }
        }

        if (target_row == -1)
            return false;

        int l = 0, h = c - 1;

        while (l <= h) {

            int m = l + (h - l) / 2;

            if (matrix[target_row][m] == target)
                return true;

            if (matrix[target_row][m] < target)
                l = m + 1;
            else
                h = m - 1;

        }

        return false;
    }
};
*/
