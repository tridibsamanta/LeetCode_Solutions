/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 852. Peak Index in a Mountain Array
~ Link      : https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        int n = nums.size();

        if (n > 2) {

            int low = 0, high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (mid > 0 && mid < n -1) {

                    if (nums[mid] >= nums[mid + 1] && nums[mid] >= nums[mid - 1])
                        return mid;
                    else if (nums[mid - 1] > nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else if (mid == 0) {
                    if (nums[mid] >= nums[mid + 1])
                        return 0;
                    else
                        return 1;
                }
                else if (mid == n - 1) {
                    if (nums[mid] >= nums[mid - 1])
                        return n - 1;
                    else
                        return n - 2;
                }
            }
        }

        return -1;
    }
};
