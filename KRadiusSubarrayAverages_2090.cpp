/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2090. K Radius Subarray Averages
~ Link      : https://leetcode.com/problems/k-radius-subarray-averages/
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), subArrLen = 2 * k + 1;

        vector<int> ans(n, -1);

        if (n < subArrLen) {
            return ans;
        }

        long int subArrSum = 0;
        int midIdx = k;

        for (int i = 0; i < subArrLen; ++i) {
            subArrSum += nums[i];
        }

        ans[midIdx++] = (subArrSum / subArrLen);

        while (midIdx + k < n) {
            subArrSum -= nums[midIdx - k - 1];
            subArrSum += nums[midIdx + k];

            ans[midIdx] = subArrSum / subArrLen;

            ++midIdx;
        }

        return ans;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
