/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 215. Kth Largest Element in an Array
~ Link      : https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// Approach 1
/*
class Solution {
public:
    #define MAXN 10000

    int findKthLargest(vector<int>& nums, int k) {
        vector<int> negFreq(MAXN + 1, 0), posFreq(MAXN + 1, 0);

        for (int val : nums) {
            if (val <= 0)
                ++negFreq[abs(val)];
            else
                ++posFreq[val];
        }

        int res = INT_MIN;

        for (int i = MAXN; i > 0; --i) {
            k -= posFreq[i];

            if (k <= 0) {
                res = i;
                break;
            }
        }

        if (res == INT_MIN) {
            for (int i = 0; i <= MAXN; ++i) {
                k -= negFreq[i];

                if (k <= 0) {
                    res = -i;
                    break;
                }
            }
        }

        return res;
    }
};
*/
// Time Complexity - O(MAXN)
// Auxiliary Space - O(MAXN)

// Approach 2 (Using Quick-Select)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> left, mid, right;
        int pivot = nums[n - 1];

        /*
         ~ 'left' contains all elements strictly greater than pivot
         ~ 'mid' contains all elements equal to pivot
         ~ 'right' contains all elements strictly lesser than pivot
        */

        for (int i = 0; i < n; ++i) {
            if (nums[i] > pivot)
                left.emplace_back(nums[i]);
            else if (nums[i] == pivot)
                mid.emplace_back(nums[i]);
            else
                right.emplace_back(nums[i]);
        }

        int leftLen = left.size(), midLen = mid.size();

        // k'th largest element lies in the left vector
        if (k <= leftLen)
            return findKthLargest(left, k);
        // k'th largest element lies in the right vector
        else if (k > (leftLen + midLen))
            return findKthLargest(right, k - (leftLen + midLen));
        // k'th largest element equal to the current pivot
        else
            return mid.front();
    }
};

// Time Complexity - O(n), Average Case
// Auxiliary Space - O(n)
