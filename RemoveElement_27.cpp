/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 27. Remove Element
~ Link      : https://leetcode.com/problems/remove-element/
*/

// Approach 1 : (Using two-pointers from start)
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int idx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                nums[idx++] = nums[i];
        }

        return idx;
    }
};
*/

// Approach 2 : (Using two-pointers from both ends)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int l = 0, r = nums.size();

        while (l < r) {

            if (nums[l] == val) {
                nums[l] = nums[r - 1];
                --r;
            }
            else {
                ++l;
            }
        }

        return r;
    }
};
