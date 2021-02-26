/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 121. Best Time to Buy and Sell Stock
~ Link      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if (n == 1)
            return 0;

        int minPrice = prices[0], profit = 0;

        for (int i = 1; i < n; ++i) {

            if (prices[i] > minPrice)
                profit = max(profit, prices[i] - minPrice);
            else
                minPrice = prices[i];
        }

        return profit;
    }
};

// T.C. - O(n)
// S.C. - O(1)
