/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 7. Reverse Integer
~ Link      : https://leetcode.com/problems/reverse-integer/
*/

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while (x) {
            // extract the current last digit
            int lastDigit = x % 10;
            x /= 10;

            // 32-bit integer overflow check
            if ((revNum > INT_MAX / 10) ||
                (revNum == INT_MAX / 10 && lastDigit > 7))
                return 0;

            if ((revNum < INT_MIN / 10) ||
                (revNum == INT_MIN / 10 && lastDigit < -8))
                return 0;

            // form the reverse integer
            revNum = revNum * 10 + lastDigit;
        }

        return revNum;
    }
};

// Time Complexity - O(log x)
// Space Complexity - O(1)
