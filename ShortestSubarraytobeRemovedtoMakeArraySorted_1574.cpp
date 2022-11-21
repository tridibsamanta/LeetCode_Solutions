/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1574. Shortest Subarray to be Removed to Make Array Sorted
~ Link      : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
*/

/* Approach 1 (Using Binary Search) */
/*
class Solution {
public:
    vector<bool> leftToRightSortedLen, rightToLeftSortedLen;

    bool isPossible(int k, vector<int>& arr) {
        int n = arr.size();

        if (leftToRightSortedLen[n - k - 1] ||
           rightToLeftSortedLen[k])
            return true;

        for (int i = 1; i < n - k; ++i) {
            if (leftToRightSortedLen[i - 1] &&
               rightToLeftSortedLen[i + k] &&
               arr[i - 1] <= arr[i + k])
                return true;
        }

        return false;
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        leftToRightSortedLen.resize(n, true);
        rightToLeftSortedLen.resize(n, true);

        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1] || !leftToRightSortedLen[i - 1])
                leftToRightSortedLen[i] = false;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1] || !rightToLeftSortedLen[i + 1])
                rightToLeftSortedLen[i] = false;
        }

        if (leftToRightSortedLen[n - 1])
            return 0;

        int lo = 1, hi = n - 1, ans;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, arr)) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
};
*/
// Time Complexity - O(n log n)
// Space Complexity - O(n)

/* Approach 2 (Using Two Pointers) */

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        int r = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1])
                r = i;
            else
                break;
        }

        int l = 0, removals = r;

        while (l < r && (l == 0 || arr[l] >= arr[l - 1])) {

            while (r < n && arr[l] > arr[r]) {
                ++r;
            }

            removals = min(removals, r - l - 1);

            ++l;
        }

        return removals;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
