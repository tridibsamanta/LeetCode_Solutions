/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 119. Pascal's Triangle II
~ Link      : https://leetcode.com/problems/pascals-triangle-ii/
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res(rowIndex + 1);
        res[0] = 1;

        for (int rowNo = 1; rowNo <= rowIndex; ++rowNo) {
            for (int j = rowNo; j > 0; --j)
                res[j] = res[j] + res[j - 1];
        }
        return res;
    }
};
