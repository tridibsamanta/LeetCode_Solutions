/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 50. Pow(x, n)
~ Link      : https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;

        if (n < 0) {
            x = 1 / x;
            n = abs(n);
        }

        while (n > 0) {
            if ((n & 1) != 0)
                res *= x;

            x *= x;
            n >>= 1;
        }

        return res;
    }
};

// Time Complexity - O(log n)
// Space Complexity - O(1)
