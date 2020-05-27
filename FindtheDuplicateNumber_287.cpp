/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 287. Find the Duplicate Number
~ Link      : https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slowPtr = nums[0];
        int fastPtr = nums[0];

        do {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        slowPtr = nums[0];

        while (slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }

        return fastPtr;

    }
};
