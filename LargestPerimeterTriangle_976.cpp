/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 976. Largest Perimeter Triangle
~ Link      : https://leetcode.com/problems/largest-perimeter-triangle/
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i > 1; --i) {
            if (A[i - 1] + A[i - 2] > A[i])
                return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};
