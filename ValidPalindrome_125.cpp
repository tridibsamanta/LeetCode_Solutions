/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 125. Valid Palindrome
~ Link      : https://leetcode.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int len = s.length();

        if (len == 0 || len == 1)
            return true;

        int l = 0, r = len - 1;

        while (l < r) {

            while (!isalnum(s[l]) && l < r)
                ++l;

            while (!isalnum(s[r]) && l < r)
                --r;

            if (tolower(s[l++]) != tolower(s[r--]))
                return false;

        }

        return true;
    }
};
