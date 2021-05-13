/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1052. Grumpy Bookstore Owner
~ Link      : https://leetcode.com/problems/grumpy-bookstore-owner/
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {

        int n = customers.size();
        int currCustomers = 0;

        for (int i = 0; i < n; ++i) {
            if (!grumpy[i])
                currCustomers += customers[i];
        }

        int maxCustomers = currCustomers;

        for (int i = 0; i < n; ++i) {

            if (grumpy[i])
                currCustomers += customers[i];

            if (i >= X) {
                if (grumpy[i - X])
                    currCustomers -= customers[i - X];
            }

            maxCustomers = max(maxCustomers, currCustomers);
        }

        return maxCustomers;
    }
};

// T.C. - O(n)
// S.C. - O(1)
