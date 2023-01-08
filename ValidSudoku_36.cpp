/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 36. Valid Sudoku
~ Link      : https://leetcode.com/problems/valid-sudoku/
*/

class Solution {
public:
    bool areAllRowsAndColumnsValid(vector<vector<char>>& board) {
        /*
         * Iterate over each cell in the 9x9 board
         */
        vector<unordered_set<char> > colDigits(9);

        for (int row = 0; row < 9; ++row) {

            unordered_set<char> rowDigits;

            for (int col = 0; col < 9; ++col) {

                if (board[row][col] != '.') {

                    if (rowDigits.count(board[row][col]) > 0 ||
                        colDigits[col].count(board[row][col]) > 0)
                            return false;
                    else {
                        rowDigits.insert(board[row][col]);
                        colDigits[col].insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }

    bool areAll3x3GridsValid(vector<vector<char>>& board) {
        /*
         * board[startRow][startCol] is the top-left corner cell
         * in each of the 3x3 grids
         */
        for (int startRow = 0; startRow <= 6; startRow += 3) {
            for (int startCol = 0; startCol <= 6; startCol += 3) {

                unordered_set<char> digits;

                /*
                 * Iterate over each cell in a 3x3 grid
                 */
                for (int row = startRow; row <= startRow + 2; ++row) {
                    for (int col = startCol; col <= startCol + 2; ++col) {

                        if (board[row][col] != '.') {

                            if (digits.count(board[row][col]) > 0)
                                return false;
                            else
                                digits.insert(board[row][col]);
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return (areAllRowsAndColumnsValid(board) &&
                areAll3x3GridsValid(board));
    }
};

// Time Complexity - O(9 x 9)
// Space Complexity - O(9 x 9)
