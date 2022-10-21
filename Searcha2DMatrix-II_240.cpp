/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 240. Search a 2D Matrix II
~ Link      : https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int currRow = 0, currCol = col - 1;
        bool targetFound = false;

        while (currRow < row && currCol >= 0) {
            if (matrix[currRow][currCol] == target) {
                targetFound = true;
                break;
            }
            else if (matrix[currRow][currCol] > target)
                --currCol;
            else
                ++currRow;
        }

        return targetFound;
    }
};

// Time Complexity - O(row + col)
// Auxiliary Space - O(1)
