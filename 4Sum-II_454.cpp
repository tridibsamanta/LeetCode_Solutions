/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 454. 4Sum II
~ Link      : https://leetcode.com/problems/4sum-ii/
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        if (A.empty())
            return 0;

        int count = 0, n = A.size();
        unordered_map<int, int> two_sum;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++two_sum[A[i] + B[j]];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                    count += two_sum[- C[i] - D[j]];
            }
        }

        return count;
    }
};
