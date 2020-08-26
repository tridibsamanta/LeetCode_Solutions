/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 977. Squares of a Sorted Array
~ Link      : https://leetcode.com/problems/squares-of-a-sorted-array/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        int n = A.size();
        vector<int> res(n);

        int l = 0, r = n - 1;

        for (int i = n - 1; i >= 0; --i) {

            if (abs(A[l]) > abs(A[r])) {
                res[i] = A[l] * A[l];
                ++l;
            }
            else {
                res[i] = A[r] * A[r];
                --r;
            }
        }
        return res;
    }
};
