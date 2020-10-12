/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 81. Search in Rotated Sorted Array II
~ Link      : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {

            // Eliminate duplicates on the left
            while (low < high && (nums[low] == nums[low + 1]))
                ++low;
            // Eliminate duplicates on the right
            while (low < high && (nums[high] == nums[high - 1]))
                --high;

            // If elements at the extreme end are equal dont consider one of them
            if (nums[low] == nums[high])
                --high;

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[low] <= nums[mid]) {

                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {

                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
