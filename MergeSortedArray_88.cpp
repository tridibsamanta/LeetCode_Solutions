/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 88. Merge Sorted Array
~ Link      : https://leetcode.com/problems/merge-sorted-array/
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k = m + n - 1, mIdx = m - 1, nIdx = n - 1;

        while (mIdx >= 0 && nIdx >= 0) {

            if (nums2[nIdx] > nums1[mIdx]) {
                nums1[k] = nums2[nIdx];
                --k; --nIdx;
            }
            else {
                nums1[k] = nums1[mIdx];
                --k; --mIdx;
            }
        }

        while (nIdx >= 0) {
            nums1[k] = nums2[nIdx];
            --k; --nIdx;
        }
    }
};
