/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1464. Maximum Product of Two Elements in an Array
~ Link      : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};
