/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1523. Count Odd Numbers in an Interval Range
~ Link      : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
*/

class Solution {
public:
    int countOdds(int low, int high) {

        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;

        return ((high - low) / 2 + 1);

    }
};
