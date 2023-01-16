/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1027. Longest Arithmetic Subsequence
~ Link      : https://leetcode.com/problems/longest-arithmetic-subsequence/
*/

/* Brute-force Approach */
/*
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int maxLen = 2;

        for (int d = -500; d <= 500; ++d) {

            for (int i = 0; i < nums.size(); ++i) {

                int prevVal = nums[i];
                int currLen = 1;

                for (int j = i + 1; j < nums.size(); ++j) {
                    if (prevVal + d == nums[j]) {
                        ++currLen;
                        prevVal = nums[j];
                    }
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};
*/
// Time Complexity - O(n^2 * d), where d = all possible differences
// Auxiliary Space - O(1)

/* Bottom-Up (Tabulation) Approach */

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;

        vector<int> lastOccIdx(501, -1);
        lastOccIdx[nums[0]] = 0;

        vector<vector<int> > dp(n, vector<int> (1001, 0));

        for (int i = 1; i < n; ++i) {

            for (int diff = -500; diff <= 500; ++diff) {

                int prevVal = nums[i] - diff, prevValIdx = -1;

                if (prevVal >= 0 && prevVal <= 500)
                    prevValIdx = lastOccIdx[prevVal];

                if (prevValIdx != -1) {
                    int col = diff + 500; // adjust according to the dp matrix

                    dp[i][col] = dp[prevValIdx][col] + 1;
                    maxLen = max(maxLen, dp[i][col]);
                }
            }

            lastOccIdx[nums[i]] = i;
        }

        return maxLen + 1;
    }
};

// Time Complexity - O(n * d), where d = all possible differences
// Auxiliary Space - O(n * d)
