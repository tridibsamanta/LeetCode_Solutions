/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 896. Monotonic Array
~ Link      : https://leetcode.com/problems/monotonic-array/
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        if (A.size() <= 2)
            return true;

        int i = 1;
        while(A[i] == A[i - 1]) {
            ++i;
            if (i == A.size())
                return true;
        }

        bool ascending = true;
        if (A[i-1] > A[i])
            ascending = false;

        for (int j = i+1; j < A.size(); ++j) {
            if (A[j - 1] > A[j] && ascending)
                return false;
            if (A[j - 1] < A[j] && !ascending)
                return false;
        }

        return true;
    }
};

/* Alternate Approach */
/*
class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        bool ascending = true, descending = true;

        for (int i = 1; i < A.size(); ++i) {

            if (A[i] < A[i-1])
                ascending = false;
            if (A[i] > A[i-1])
                descending = false;
        }

        return ascending || descending;
    }
};
*/
