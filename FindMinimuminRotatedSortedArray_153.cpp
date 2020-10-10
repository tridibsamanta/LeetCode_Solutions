/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 153. Find Minimum in Rotated Sorted Array
~ Link      : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {

            // If array is sorted, element at index 'low' is minimum
            if (nums[low] <= nums[high])
                return nums[low];

            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            // Element at index 'mid' is minimum if
            // it is lesser than its previous element AND next element
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];
            // Minimum element lies in the unsorted segment
            else if (nums[mid] >= nums[low])
                low = mid + 1;
            else if (nums[mid] <= nums[high])
                high = mid - 1;
        }
        return -1;
    }
};
