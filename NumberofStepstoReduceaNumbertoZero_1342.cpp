/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1342. Number of Steps to Reduce a Number to Zero
~ Link      : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
*/

class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while (num) {
            if (num % 2 != 0) {
                --num;
                ++steps;
            }
            if (num != 0) {
                num = num / 2;
                ++steps;
            }
        }
        return steps;
    }
};
