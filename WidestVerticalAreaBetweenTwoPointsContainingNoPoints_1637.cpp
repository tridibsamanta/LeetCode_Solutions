/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1637. Widest Vertical Area Between Two Points Containing No Points
~ Link      : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int res = 0;

        for (int i = 0; i < points.size() - 1; ++i) {
            res = max(res, (points[i + 1][0] - points[i][0]));
        }

        return res;
    }
};
