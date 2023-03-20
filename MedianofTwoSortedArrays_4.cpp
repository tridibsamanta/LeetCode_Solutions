/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 4. Median of Two Sorted Arrays
~ Link      : https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;
        double median;

        while (lo <= hi) {
            int cut1 = lo + (hi - lo) / 2;
            int cut2 = ((m + n + 1) / 2) - cut1;

            int nums1_leftMax = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            int nums2_leftMax = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);

            int nums1_rightMin = (cut1 == m ? INT_MAX : nums1[cut1]);
            int nums2_rightMin = (cut2 == n ? INT_MAX : nums2[cut2]);

            if (nums1_leftMax <= nums2_rightMin && nums2_leftMax <= nums1_rightMin) {
                if ((m + n) & 1)
                    median = max(nums1_leftMax, nums2_leftMax);
                else
                    median = (max(nums1_leftMax, nums2_leftMax) + min(nums1_rightMin, nums2_rightMin)) / 2.0;

                break;
            }
            else if (nums1_leftMax > nums2_rightMin) {
                hi = cut1 - 1;
            }
            else if (nums2_leftMax > nums1_rightMin) {
                lo = cut1 + 1;
            }
        }

        return median;
    }
};

// T.C. - O(log * min(nums1.size(), nums2.size()))
// S.C. - O(1)
