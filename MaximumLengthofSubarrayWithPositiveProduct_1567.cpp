/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1567. Maximum Length of Subarray With Positive Product
~ Link      : https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int posCnt = 0, negCnt = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                posCnt = negCnt = 0;
            }
            else if (nums[i] > 0) {
                ++posCnt;

                if (negCnt != 0)
                    ++negCnt;
            }
            else if (nums[i] < 0) {
                swap(posCnt, negCnt);

                ++negCnt;

                if (posCnt != 0)
                    ++posCnt;
            }

            res = max(res, posCnt);
        }

        return res;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
