/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1281. Subtract the Product and Sum of Digits of an Integer
~ Link      : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit = 0, sum = 0, product = 1;
        while (n) {
            digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return (product - sum);
    }
};
