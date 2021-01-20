/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 581. Shortest Unsorted Continuous Subarray
~ Link      : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int l = -1, r = -1;

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                l = i;
                break;
            }
        }

        if (l == -1)
            return 0;

        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < nums[i - 1]) {
                r = i;
                break;
            }
        }

        int mx = INT_MIN, mn = INT_MAX;

        for (int i = l; i <= r; ++i) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        for (int i = 0; i < l; ++i) {
            if (mn < nums[i]) {
                l = i;
                break;
            }
        }

        for (int i = n - 1; i > r; --i) {
            if (mx > nums[i]) {
                r = i;
                break;
            }
        }

        return r - l + 1;
    }
};

// T.C. - O(n)
// S.C. - O(1)
