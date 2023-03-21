/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 410. Split Array Largest Sum
~ Link      : https://leetcode.com/problems/split-array-largest-sum/
*/

class Solution {
public:
    bool isPossible(int sum, vector<int> &nums, int m) {
        int cnt = 1, currSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currSum += nums[i];

            if (currSum > sum) {
                if (++cnt > m)
                    break;

                currSum = nums[i];
            }
        }

        return (cnt <= m);
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int lo = 0, hi = 0;

        for (auto val : nums) {
            lo = max(lo, val);
            hi += val;
        }

        int largestSum = hi;

        if (m == 1)
            return largestSum;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, nums, m)) {
                largestSum = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return largestSum;
    }
};

// T.C. - O(N * log S), where S = Sum of all elements in nums
// S.C. - O(1)
