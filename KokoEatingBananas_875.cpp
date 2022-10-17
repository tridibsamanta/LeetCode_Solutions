/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 875. Koko Eating Bananas
~ Link      : https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution {
public:
    bool isPossible(int hourlyEatingRate, vector<int> &piles, int hourLimit) {
        int hoursElapsed = 0;

        for (int i = 0; i < piles.size(); ++i) {
            int currEatingHours = (piles[i] / hourlyEatingRate) +
                                    (piles[i] % hourlyEatingRate != 0);

            hoursElapsed += currEatingHours;

            if (hoursElapsed > hourLimit)
                break;
        }

        return (hoursElapsed <= hourLimit);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxBananasInPile = *max_element(piles.begin(), piles.end());

        if (h == n)
            return maxBananasInPile;

        int lo = 1, hi = maxBananasInPile, hourlyEatingRate = maxBananasInPile;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, piles, h)) {
                hourlyEatingRate = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return hourlyEatingRate;
    }
};

// Time Complexity - O(n * log max(piles[i])), where n = piles.size()
// Auxiliary Space - O(1)
