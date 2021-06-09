/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 775. Global and Local Inversions
~ Link      : https://leetcode.com/problems/global-and-local-inversions/
*/

/* Approach 1 */

// Every local inversion is a global inversion.
// Thus we cannot have a global inversion {i,j},
// such that nums[i] > nums[j] and j - i > 1
/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), curr_max = INT_MIN;

        for (int i = 0; i < n - 2; ++i) {
            curr_max = max(curr_max, nums[i]);

            if (curr_max > nums[i + 2]) // global inversion which is not a local inversion
                return false;
        }

        return true;
    }
};
// T.C. - O(n)
*/

/* Approach 2 */

// We cannot allow a global inversion which is not a local inversion.
// Array nums contain numbers in the range [0..n-1], Ex. [0, 1, 2, 3]
// To make a global inversion which is NOT a local inversion, we need
// to shift an element strictly more than one place to its left or right.
// Ex. [2, 0, 1, 3] or [0, 3, 1, 2] or [0, 2, 3, 1]
// Thus, if abs(arr[index] - index) > 1, a global inversion is found
// which is not a local inversion, and we return false.

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {

            if (abs(nums[i] - i) > 1) // global inversion which is not a local inversion
                return false;
        }

        return true;
    }
};
// T.C. - O(n)
