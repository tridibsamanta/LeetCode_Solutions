/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 441. Arranging Coins
~ Link      : https://leetcode.com/problems/arranging-coins/
*/

class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0, r = n, mid = 0, coins = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            coins = mid * (mid + 1) / 2;
            if (coins == n)
                return (int) mid;
            if (n < coins)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return (int) r;
    }
};

// Approach 2
/*
class Solution {
public:
    int arrangeCoins(int n) {
        int curr = 1;
        while (n >= curr) {
            n -= curr;
            ++curr;
        }
        return --curr;
    }
};
*/
