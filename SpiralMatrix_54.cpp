/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 54. Spiral Matrix
~ Link      : https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> spiral;

        if (!matrix.size())
            return spiral;

        int m = matrix.size();
        int n = matrix[0].size();

        int k = 0, l = 0;

        while (k < m && l < n) {

            for (int i = l; i < n; ++i)
                spiral.push_back(matrix[k][i]);
            ++k;

            for (int i = k; i < m; ++i)
                spiral.push_back(matrix[i][n - 1]);
            --n;

            if (k < m) {
                for (int i = n - 1; i >= l; --i)
                    spiral.push_back(matrix[m - 1][i]);
                --m;
            }

            if (l < n) {
                for (int i = m - 1; i >= k; --i)
                    spiral.push_back(matrix[i][l]);
                ++l;
            }

        }
        return spiral;
    }
};
