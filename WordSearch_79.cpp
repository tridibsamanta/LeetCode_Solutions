/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 79. Word Search
~ Link      : https://leetcode.com/problems/word-search/
*/

class Solution {
public:
    vector<int> row4D = { -1, 0, 1, 0};
    vector<int> col4D = {0, 1, 0, -1};

    bool wordExist(int r, int c, vector<vector<char> > &board, int m, int n,
                   string word, int idx) {

        if (idx == word.size() - 1)
            return true;

        char currChar = board[r][c];
        board[r][c] = '#';

        for (int k = 0; k < 4; ++k) {
            int adj_r = r + row4D[k];
            int adj_c = c + col4D[k];

            if ((adj_r >= 0 && adj_r < m) && (adj_c >= 0 && adj_c < n)
               && board[adj_r][adj_c] == word[idx + 1]) {

                if (wordExist(adj_r, adj_c, board, m, n, word, idx + 1))
                    return true;
            }
        }

        board[r][c] = currChar;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (board[i][j] == word[0]) {
                    if (wordExist(i, j, board, m, n, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

// Time Complexity - O(m * n * 4^L)
// Auxiliary Space - O(m * n)
