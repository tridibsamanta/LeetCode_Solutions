/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1499. Max Value of Equation
~ Link      : https://leetcode.com/problems/max-value-of-equation/
*/

/* Approach 1 (Using Max-Heap) */
/*
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();

        int res = INT_MIN;
        priority_queue<pair<int, int> > pq; // {Yi - Xi, Xi}

        for (int i = 0; i < n; ++i) {
            int x_j = points[i][0], y_j = points[i][1];

            while (!pq.empty() && (x_j - pq.top().second > k)) {
                pq.pop();
            }

            if (!pq.empty()) {
                res = max(res, x_j + y_j + pq.top().first);
            }

            pq.push({y_j - x_j, x_j});
        }

        return res;
    }
};
*/
// Time Complexity - O(n * log n)
// Auxiliary Space - O(n)

/* Approach 2 (Using Monotonic Deque) */

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();

        int res = INT_MIN;
        deque<pair<int, int> > dq;

        for (int i = 0; i < n; ++i) {
            int x_j = points[i][0], y_j = points[i][1];

            while (!dq.empty() && (x_j - dq.front().second > k)) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                res = max(res, x_j + y_j + dq.front().first);
            }

            while (!dq.empty() && dq.back().first < (y_j - x_j)) {
                dq.pop_back();
            }

            dq.push_back({y_j - x_j, x_j});
        }

        return res;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
