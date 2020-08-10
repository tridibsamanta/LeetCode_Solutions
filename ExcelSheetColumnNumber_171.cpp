/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 171. Excel Sheet Column Number
~ Link      : https://leetcode.com/problems/excel-sheet-column-number/
*/

class Solution {
public:
    int titleToNumber(string s) {

        int colNo = 0;

        for (int i = 0; s[i]; ++i)
            colNo = (colNo * 26) + (s[i] - 'A' + 1);

        return colNo;
    }
};
