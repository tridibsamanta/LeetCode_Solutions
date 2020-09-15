/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 56. Merge Intervals
~ Link      : https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() <= 1)
            return intervals;

        vector<vector<int> > res;

        sort(intervals.begin(), intervals.end());

        res.emplace_back(intervals[0]);

        for (int i = 0; i < intervals.size(); ++i) {

            if (intervals[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.emplace_back(intervals[i]);
        }

        return res;
    }
};
