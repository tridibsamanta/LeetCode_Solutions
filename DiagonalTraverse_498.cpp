/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 498. Diagonal Traverse
~ Link      : https://leetcode.com/problems/diagonal-traverse/
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        if (matrix.size() == 0)
			return {};

		vector<int>res;

		int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r + c - 1; ++i) {

            if (i & 1) {
				for (int j = min(i, c - 1); j >= max(i - r + 1, 0); --j)
					res.emplace_back(matrix[i - j][j]);
			}
            else {
				for (int j = max(i - r + 1, 0); j <= min(i, c - 1); ++j)
					res.emplace_back(matrix[i - j][j]);
			}
		}
        return res;
    }
};
