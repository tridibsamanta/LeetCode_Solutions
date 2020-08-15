/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 118. Pascal's Triangle
~ Link      : https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int> > res;

        if (numRows == 0)
            return res;

        vector<int> row(1, 1);
        res.emplace_back(row);

        for (int rowNo = 1; rowNo < numRows; ++rowNo) {

            row.resize(rowNo + 1, 0);

            for (int j = rowNo; j > 0; --j)
                row[j] = row[j] + row[j - 1];

            res.emplace_back(row);
        }

        return res;
    }
};
