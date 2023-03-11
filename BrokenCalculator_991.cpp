/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 991. Broken Calculator
~ Link      : https://leetcode.com/problems/broken-calculator/solution/
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue >= target)
            return (startValue - target);

        int steps = 0;

        while (target > startValue) {
            ++steps;

            if (target & 1)
                ++target;
            else
                target = (target >> 1);
        }

        steps += startValue - target;
        return steps;
    }
};

// Time Complexity - O(log target)
// Auxiliary Space - O(1)
