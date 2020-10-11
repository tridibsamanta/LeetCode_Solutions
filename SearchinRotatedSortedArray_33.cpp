/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 33. Search in Rotated Sorted Array
~ Link      : https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // If element at index 'mid' is equal to target
            if (nums[mid] == target)
                return mid;

            // If left segment is sorted
            if (nums[mid] >= nums[low]) {

                // If target is probably in the left sorted segment
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                // Else target is probably in the right unsorted segment
                else
                    low = mid + 1;
            }
            // Else right segment is sorted
            else {

                // If target is probably in the right sorted segment
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                // Else target is probably in the left unsorted segment
                else
                    high = mid - 1;
            }
        }
        // target is not found
        return -1;
    }
};
