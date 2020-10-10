/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 34. Find First and Last Position of Element in Sorted Array
~ Link      : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution {
private:
    int findFirstOccurrenceIndex(vector<int> &nums, int target) {

        int low = 0, high = nums.size() - 1, idx = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                idx = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return idx;
    }

    int findLastOccurrenceIndex(vector<int> &nums, int target) {

        int low = 0, high = nums.size() - 1, idx = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                idx = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return idx;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res {-1, -1};

        res[0] = findFirstOccurrenceIndex(nums, target);

        if (res[0] == -1)
            return res;

        res[1] = findLastOccurrenceIndex(nums, target);

        return res;
    }
};
