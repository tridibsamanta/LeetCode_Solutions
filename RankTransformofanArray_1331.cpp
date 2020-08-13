/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1331. Rank Transform of an Array
~ Link      : https://leetcode.com/problems/rank-transform-of-an-array/
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> res;

        if (arr.size() == 0)
            return res;

        res = arr;
        sort(res.begin(), res.end());

        unordered_map<int, int> r;

        int rank = 1;
        r[res[0]] = rank;

        for (int i = 1; i < res.size(); ++i) {
            if (res[i] == res[i - 1])
                r[res[i]] = rank;
            else
                r[res[i]] = ++rank;
        }

        for (int i = 0; i < arr.size(); ++i)
            res[i] = r[arr[i]];

        return res;
    }
};
