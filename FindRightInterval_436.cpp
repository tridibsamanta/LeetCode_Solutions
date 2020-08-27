/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 436. Find Right Interval
~ Link      : https://leetcode.com/problems/find-right-interval/
*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> res(n, -1);
        map <int, int> idx;

        for(int i = 0; i < n; ++i)
            idx[intervals[i][0]] = i + 1;


        for(int i = 0; i < n; ++i) {

            auto it = idx.lower_bound(intervals[i][1]);

            if(it -> second != 0)
                res[i] = it -> second - 1;
        }

        return res;
    }
};
