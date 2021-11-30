/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2091. Removing Minimum and Maximum From Array
~ Link      : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 1;
        }

        int minVal = INT_MAX, minValIdx = -1;
        int maxVal = INT_MIN, maxValIdx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minValIdx = i;
            }

            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxValIdx = i;
            }
        }

        int minIdx = min(minValIdx, maxValIdx);
        int maxIdx = max(minValIdx, maxValIdx);

        int ans = maxIdx + 1;
        ans = min(ans, n - minIdx);
        ans = min(ans, (minIdx + 1) + (n - maxIdx));

        return ans;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
