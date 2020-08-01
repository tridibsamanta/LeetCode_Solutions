/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 278. First Bad Version
~ Link      : https://leetcode.com/problems/first-bad-version/
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid;
        while(l < r) {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
