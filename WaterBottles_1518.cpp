/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1518. Water Bottles
~ Link      : https://leetcode.com/problems/water-bottles/
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        if (numBottles < numExchange)
            return numBottles;

        if (numBottles == numExchange)
            return ++numBottles;

        int drinkCount = numBottles, emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int exchange = emptyBottles / numExchange;
            drinkCount += exchange;
            emptyBottles %= numExchange;
            emptyBottles += exchange;
        }

        return drinkCount;
    }
};
