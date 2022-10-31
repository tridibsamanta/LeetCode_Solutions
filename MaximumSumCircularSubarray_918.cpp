/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 918. Maximum Sum Circular Subarray
~ Link      : https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

class Solution {
public:
    int minSubarraySum(vector<int> &nums) {
        int minSum = nums[0], currSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];

            if (currSum < minSum)
                minSum = currSum;

            if (currSum > 0)
                currSum = 0;
        }

        return minSum;
    }

    int maxSubarraySum(vector<int> &nums) {
        int maxSum = nums[0], currSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];

            if (currSum > maxSum)
                maxSum = currSum;

            if (currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubarraySum(nums);
        int minSum = minSubarraySum(nums);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        return (maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum);
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
