/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 53. Maximum Subarray
~ Link      : https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = nums[0], currSum = 0;

        for (int i = 0; i < nums.size(); ++i) {

            currSum += nums[i];

            maxSum = max(maxSum, currSum);

            if (currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }
};
