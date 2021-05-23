/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1833. Maximum Ice Cream Bars
~ Link      : https://leetcode.com/problems/maximum-ice-cream-bars/
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        if (costs[0] > coins)
            return 0;

        for (int i = 0; i < costs.size(); ++i) {
            if ((coins -= costs[i]) < 0)
                return i;
        }

        return costs.size();
    }
};

// Runtime - O(nlogn)
// Auxiliary space - O(1)
