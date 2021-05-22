/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1482. Minimum Number of Days to Make m Bouquets
~ Link      : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*/

class Solution {
public:
    // Step 3: Design the predicate function
    bool isPossible(int days, vector<int>& bloomDay, int n, int m, int k) {

        int bouquets = 0, curr_k = 0;

        for (int i = 0; i < n; ++i) {

            if (bloomDay[i] <= days) {
                if (++curr_k == k) {
                    if (++bouquets == m)
                        return true;

                    curr_k = 0;
                }
            }
            else {
                curr_k = 0;
            }
        }

        return false;
    }

    // Step 2: Perform binary search in the search space [lo, hi]
    int getMinDays(int lo, int hi, vector<int>& bloomDay, int n, int m, int k) {

        int minDays = hi;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, bloomDay, n, m, k)) {
                minDays = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return minDays;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if (n < m * k)
            return -1;

        // Step 1: Find the lo and hi of the initital search space
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        return getMinDays(lo, hi, bloomDay, n, m, k);
    }
};

/*
 ~ T.C. - O(n * log k) where, n = bloomDay.size() &
   k = max(bloomDay[0], ..., bloomDay[n - 1])
 ~ S.C. - O(1)
*/
