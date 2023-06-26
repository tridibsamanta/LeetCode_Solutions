/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2462. Total Cost to Hire K Workers
~ Link      : https://leetcode.com/problems/total-cost-to-hire-k-workers/
*/

class Solution {
public:
    long long totalCostUtil1(vector<int> &costs, int k, int candidates) {
        int l = candidates, r = costs.size() - candidates - 1;
        long long hiringCost = 0;

        priority_queue<int, vector<int>, greater<int> > leftPq(costs.begin(), costs.begin() + l);
        priority_queue<int, vector<int>, greater<int> > rightPq(costs.begin() + r + 1, costs.end());

        while (k > 0 && l <= r) {
            if (leftPq.top() <= rightPq.top()) {
                hiringCost += leftPq.top();
                leftPq.pop();
                leftPq.push(costs[l++]);
            }
            else {
                hiringCost += rightPq.top();
                rightPq.pop();
                rightPq.push(costs[r--]);
            }

            --k;
        }

        if (k > 0) {
            while (!rightPq.empty()) {
                leftPq.push(rightPq.top());
                rightPq.pop();
            }

            while (k--) {
                hiringCost += leftPq.top();
                leftPq.pop();
            }
        }

        return hiringCost;
    }

    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long hiringCost = 0;

        if (candidates <= costs.size() / 2)
            hiringCost = totalCostUtil1(costs, k, candidates);
        else {
            priority_queue<int, vector<int>, greater<int> > pq(costs.begin(), costs.end());

            while (k--) {
                hiringCost += pq.top();
                pq.pop();
            }
        }

        return hiringCost;
    }
};

// Time Complexity - O(n log n), where n = costs.length
// Auxiliary Space - O(n)
