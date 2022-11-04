/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1326. Minimum Number of Taps to Open to Water a Garden
~ Link      : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
*/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> span(n + 1);

        for (int i = 0; i < n + 1; ++i) {
            int startIndex = max(0, i - ranges[i]);
            int endIndex = min(n, i + ranges[i]);

            span[startIndex] = max(span[startIndex], endIndex - startIndex);
        }

        int tapCount = 0, currReach = 0, maxReach = 0;

        for (int i = 0; i < n; ++i) {
            maxReach = max(maxReach, i + span[i]);

            if (i == maxReach)
                return -1;

            if (i == currReach) {
                ++tapCount;
                currReach = maxReach;

                if (currReach >= n)
                    break;
            }
        }

        return tapCount;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
