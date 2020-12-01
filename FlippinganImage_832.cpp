/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 832. Flipping an Image
~ Link      : https://leetcode.com/problems/flipping-an-image/
*/

/* Straight-forward Implementation */

/*
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        int m = A.size();
        int n = A[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 0)
                    A[i][j] = 1;
                else
                    A[i][j] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(A[i][j], A[i][n - 1 - j]);
            }
        }

        return A;
    }
};
*/

/* Using XOR (^) to toggle values*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        int m = A.size();
        int n = A[0].size();

        for (int i = 0; i < m; ++i) {

            reverse(A[i].begin(), A[i].end());

            for (int j = 0; j < n; ++j)
                A[i][j] ^= 1;

        }

        return A;
    }
};
