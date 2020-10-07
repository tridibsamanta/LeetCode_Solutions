/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 162. Find Peak Element
~ Link      : https://leetcode.com/problems/find-peak-element/
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if (n > 1) {

            int low = 0, high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                // If nums[mid] is not an edge element
                if (mid > 0 && mid < n -1) {

                    if (nums[mid] >= nums[mid + 1] && nums[mid] >= nums[mid - 1])
                        return mid;
                    else if (nums[mid - 1] > nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                // If nums[mid] is the leftmost element
                else if (mid == 0) {

                    if (nums[mid] >= nums[mid + 1])
                        return 0;
                    else
                        return 1;
                }
                // If nums[mid] is the rightmost element
                else if (mid == n - 1) {

                    if (nums[mid] >= nums[mid - 1])
                        return n - 1;
                    else
                        return n - 2;
                }
            }
        }

        // If array contains a single element
        return 0;
    }
};
