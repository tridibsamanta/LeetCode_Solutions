/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1221. Split a String in Balanced Strings
~ Link      : https://leetcode.com/problems/split-a-string-in-balanced-strings/
*/

class Solution {
public:
    int balancedStringSplit(string s) {

        int splits = 0, check = 0;

        for (int i = 0; i < s.length(); ++i) {

            if (s[i] == 'R')
                ++check;
            else
                --check;

            if (!check)
                ++splits;
        }

        return splits;
    }
};
