/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 168. Excel Sheet Column Title
~ Link      : https://leetcode.com/problems/excel-sheet-column-title/
*/

class Solution {
public:
    string convertToTitle(int n) {

        string res = "";

        while (n > 0) {

            int rem = n % 26;

            if (rem == 0) {
                res += 'Z';
                n = n / 26 - 1;
            }
            else {
                res += ('A' + --rem);
                n = n / 26;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
