/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 566. Reshape the Matrix
~ Link      : https://leetcode.com/problems/reshape-the-matrix/
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        int nums_r = nums.size();
        int nums_c = nums[0].size();

        if ((nums_r * nums_c) != (r * c))
            return nums;

        vector<vector<int> > matrix(r);

        int curr_row = 0, curr_col = 0;

        for (int i = 0; i < nums_r; ++i) {
            for (int j = 0; j < nums_c; ++j) {

                if (curr_col < c) {
                    matrix[curr_row].emplace_back(nums[i][j]);
                    ++curr_col;
                }
                else {
                    matrix[++curr_row].emplace_back(nums[i][j]);
                    curr_col = 1;
                }
            }
        }

        return matrix;
    }
};
