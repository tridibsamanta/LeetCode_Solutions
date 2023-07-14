/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1679. Max Number of K-Sum Pairs
~ Link      : https://leetcode.com/problems/max-number-of-k-sum-pairs/
*/

/* Approach 1 (Using Sorting) */
/*
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = n - 1, pairCount = 0;

        while (l < r) {
            int currPairSum = nums[l] + nums[r];

            if (currPairSum == k) {
                ++pairCount;
                ++l;
                --r;
            }
            else if (currPairSum < k) {
                ++l;
            }
            else if (currPairSum > k) {
                --r;
            }
        }

        return pairCount;
    }
};
*/
// Time Complexity - O(n log n)
// Space Complexity - O(1)

/* Approach 2 (Using Map) */

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), pairCount = 0;

        unordered_map<int, int> freq;

        for (auto val : nums) {
            if (freq[k - val] > 0) {
                ++pairCount;
                --freq[k - val];
            }
            else
                ++freq[val];
        }

        return pairCount;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
