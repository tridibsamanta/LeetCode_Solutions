/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1004. Max Consecutive Ones III
~ Link      : https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {

        int max_cnt = 0, l = 0, r = 0, flips = 0;

        for (; r < A.size(); ++r) {

            if (A[r] == 0)
                ++flips;

            while (flips > K && A[l++] == 0) {
                --flips;
            }

            max_cnt = max(max_cnt, r - l + 1);
        }

        return max_cnt;
    }
};
