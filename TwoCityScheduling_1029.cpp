/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1029. Two City Scheduling
~ Link      : https://leetcode.com/problems/two-city-scheduling/
*/

// Approach 1 (Using Sorting)

class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        // Sort based on decreasing profit,
        // where profit (if we fly to city A rather than city B) = cost of flying to city B - cost of flying to city A
        return a[1] - a[0] > b[1] - b[0];
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {

        int n = costs.size();

        sort(costs.begin(), costs.end(), comparator);

        int minCost = 0;

        for (int i = 0; i < n/2; ++i)
            minCost += costs[i][0];
        for (int i = n/2; i < n; ++i)
            minCost += costs[i][1];

        return minCost;
    }
};

// T.C. - O(nlogn)
// S.C. - O(1)

// Approach 2 (Using Heap)
/*
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        int n = costs.size();

        // pair -> {profit if we travel to city A than city B, index}
        priority_queue<pair<int, int> > pq;

        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(costs[i][1] - costs[i][0], i));
        }

        int minCost = 0;

        n /= 2;

        // Adding costs to travel to city A
        while (n--) {
            pair<int, int> curr = pq.top();
            minCost += costs[curr.second][0];
            pq.pop();
        }

        // Adding costs to travel to city B
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            minCost += costs[curr.second][1];
            pq.pop();
        }

        return minCost;
    }
};
*/
// T.C. - O(nlogn)
// S.C. - O(n)
