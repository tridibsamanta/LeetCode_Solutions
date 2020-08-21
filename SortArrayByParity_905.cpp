/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 905. Sort Array By Parity
~ Link      : https://leetcode.com/problems/sort-array-by-parity/
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        int left = 0, right = A.size() - 1;

        while(left < right) {

            while(!(A[left] & 1) && left < right) {
            ++left;
            }

            while((A[right] & 1) && left < right) {
            --right;
            }

            if (left < right) {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                ++left;
                --right;
            }
        }

        return A;
    }
};
