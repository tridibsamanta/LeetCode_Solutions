/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 130. Surrounded Regions
~ Link      : https://leetcode.com/problems/surrounded-regions/
*/

class Solution {
private:
    void dfsUtil(int i, int j, vector<vector<char>>& board, int rows, int columns) {

        static int rowPos[] = {-1, 1, 0, 0};
        static int colPos[] = {0, 0, -1, 1};

        if ((i < 0 || i >= rows) || (j < 0 || j >= columns) ||
            board[i][j] != 'O')
            return;

        board[i][j] = '*';

        for (int k = 0; k < 4; ++k)
            dfsUtil(i + rowPos[k], j + colPos[k], board, rows, columns);

    }

public:
    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        if (rows == 0)
            return;
        int columns = board[0].size();

        for (int i = 0; i < columns; ++i) {
            if (board[0][i] == 'O')
                dfsUtil(0, i, board, rows, columns);
            if (board[rows - 1][i] == 'O')
                dfsUtil(rows - 1, i, board, rows, columns);
        }

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O')
                dfsUtil(i, 0, board, rows, columns);
            if (board[i][columns - 1] == 'O')
                dfsUtil(i, columns - 1, board, rows, columns);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};
