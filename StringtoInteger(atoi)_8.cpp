/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 8. String to Integer (atoi)
~ Link      : https://leetcode.com/problems/string-to-integer-atoi/
*/

class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();

        if (n == 0)
            return 0;

        int num = 0;
        int i = 0, sign = 1;

        // Ignore whitespaces(' ') in the beginning
        while (i < n && s[i] == ' ')
            ++i;

        // '+' / '-' sign check
        if (i < n) {
            if (s[i] == '-') {
                sign = -1;
                ++i;
            }
            else if (s[i] == '+') {
                sign = 1;
                ++i;
            }
        }

        // Construct the integer
        for (; i < n; ++i) {

            // If current character is not a digit
            if (!(s[i] >= '0' && s[i] <= '9'))
                break;

            // Overflow / Underflow check
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            num = num * 10 + (s[i] - '0');
        }

        return sign * num;
    }
};
