/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 409. Longest Palindrome
~ Link      : https://leetcode.com/problems/longest-palindrome/
*/

class Solution {
public:
    int longestPalindrome(string s) {

        int freq[58];
        memset(freq, 0, sizeof(freq));

        for (int i = 0; s[i]; ++i)
            ++freq[s[i] - 'A'];

        int length = 0;
        bool odd = false;

        for (int i = 0; i < 58; ++i) {
            if (freq[i] & 1) {
                odd = true;
                length += freq[i] - 1;
            }
            else {
                length += freq[i];
            }
        }

        return (odd) ? ++length : length;
    }
};
