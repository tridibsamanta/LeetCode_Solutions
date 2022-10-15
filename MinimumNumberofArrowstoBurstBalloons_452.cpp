/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 452. Minimum Number of Arrows to Burst Balloons
~ Link      : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

class Solution {
public:
    // sort the segments based on end points in ascending order
    static bool compare(const vector<int> &point1, const vector<int> &point2) {
        return point1[1] < point2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);

        int arrowCount = 1, shootPoint = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > shootPoint) {
                shootPoint = points[i][1];
                ++arrowCount;
            }
        }

        return arrowCount;
    }
};

// Time Complexity - O(n * log n), where n = points.size()
// Auxiliary Space - O(1)
