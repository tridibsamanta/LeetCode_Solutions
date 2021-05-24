/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1011. Capacity To Ship Packages Within D Days
~ Link      : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

class Solution {
public:
    // Step 3: Design the predicate function
    bool isPossible(int wt, vector<int>& weights, int days) {

        int curr_days = 1, rem_wt = wt;

        for (auto w : weights) {
            if (w > rem_wt) {
                if (++curr_days > days)
                    return false;

                rem_wt = wt - w;
            }
            else {
                rem_wt -= w;
            }
        }

        return curr_days <= days;
    }

    // Step 2: Perform binary search in the search space [lo, hi]
    int shipWithinDaysUtil(int lo, int hi, vector<int>& weights, int days) {

        int minWeight = hi;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, weights, days)) {
                minWeight = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return minWeight;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        // Step 1: Find the lo and hi of the initital search space
        int lo = INT_MIN, hi = 0;

        for (auto w : weights) {
            lo = max(lo, w);
            hi += w;
        }

        return shipWithinDaysUtil(lo, hi, weights, days);
    }
};

/*
 ~ T.C. - O(n * log k)
   where, n = weights.size() and
   k = weights[0] + weights[1] + ... + weights[n - 1]
 ~ S.C. - O(1)
*/
