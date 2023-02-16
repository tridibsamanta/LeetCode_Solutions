/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 739. Daily Temperatures
~ Link      : https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> daysToWait(n, 0);
        stack<pair<int, int> > stk;

        for (int i = n - 1; i >= 0; --i) {
            if (!stk.empty()) {

                while (!stk.empty() && temperatures[i] >= stk.top().first) {
                    stk.pop();
                }

                if (!stk.empty())
                    daysToWait[i] = stk.top().second - i;
            }

            stk.push({temperatures[i], i});
        }

        return daysToWait;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
