/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 258. Add Digits
~ Link      : https://leetcode.com/problems/add-digits/
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};
