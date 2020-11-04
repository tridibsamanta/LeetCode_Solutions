/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 345. Reverse Vowels of a String
~ Link      : https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

/* Approach 1 (Using an auxiliary string) */

/*
class Solution {
public:
    string reverseVowels(string s) {

        int len = s.length();

        if (len <= 1)
            return s;

        string vowels = "";

        for (int i = 0; s[i]; ++i)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                vowels += s[i];

        int n = vowels.length();

        if (n <= 1)
            return s;

        int i = 0, j = n - 1;

        while (i < j) {
            char temp = vowels[i];
            vowels[i] = vowels[j];
            vowels[j] = temp;
            ++i; --j;
        }

        j = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                s[i] = vowels[j++];
        }

        return s;
    }
};
*/

/* Approach 2 (Using two-pointers) */

class Solution {
public:
    string reverseVowels(string s) {

        int len = s.length();

        if (len <= 1)
            return s;

        int i = 0, j = len - 1;

        while (i < j) {

            while (i < j && (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'))
                ++i;

            while (i < j && (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U'))
                --j;

            if (i < j) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                ++i; --j;
            }
        }

        return s;
    }
};
