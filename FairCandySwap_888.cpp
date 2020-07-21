/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 888. Fair Candy Swap
~ Link      : https://leetcode.com/problems/fair-candy-swap/
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        vector<int> res(2);
        int sumA = 0, sumB = 0;

        for (int i = 0; i < A.size(); ++i)
            sumA += A[i];
        for (int i = 0; i < B.size(); ++i)
            sumB += B[i];

        int x = (sumB - sumA) / 2;

        set<int> s;
        for (int i = 0; i < B.size(); ++i)
            s.insert(B[i]);

        for (int i = 0; i < A.size(); ++i) {
            if (s.find(A[i] + x) != s.end()) {
                res[0] = A[i];
                res[1] = A[i] + x;
            }
        }

        return res;
    }
};
