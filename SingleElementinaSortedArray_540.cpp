/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 540. Single Element in a Sorted Array
~ Link      : https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

/*
    Intuition:

    1.  Partition the array into 2 halves such that
        all elements in the left half occur exactly twice.

    2.  The element at the partition index is the element
        which appears exactly once.

        Example:

                0  1  2  3  4  5  6  7  8
        nums = [1, 1, 2, 2, 3, 4, 4, 5, 5]
                            ^
        partion index   -> 4
        left half       -> index 0 to 3
        right half      -> index 4 to 8

    3.  For left half duplicates we observe:
        ~ 1st occurrence is present at an even index.
        ~ 2nd occurrence is present at an odd index.

    4.  For right half duplicates we observe:
        ~ 1st occurrence is present at an odd index.
        ~ 2nd occurrence is present at an even index.

    5.  Binary search for the partition index and return
        the element present at this partition index.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 2;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid & 1) {
                // we are in the left half
                if (nums[mid] == nums[mid - 1])
                    lo = mid + 1;
                // we are in the right half
                else
                    hi = mid - 1;
            }
            else {
                // we are in the left half
                if (nums[mid] == nums[mid + 1])
                    lo = mid + 1;
                // we are in the right half
                else
                    hi = mid - 1;
            }
        }

        return nums[lo];
    }
};

// Time Complexity - O(log n)
// Auxiliary Space - O(1)
