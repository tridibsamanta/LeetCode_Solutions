/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 709. To Lower Case
~ Link      : https://leetcode.com/problems/to-lower-case/
*/

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + ' ';
            }
        }
        return str;
    }
};
