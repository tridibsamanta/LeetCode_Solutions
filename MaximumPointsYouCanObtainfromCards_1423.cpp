/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1423. Maximum Points You Can Obtain from Cards
~ Link      : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int maxPoints = 0;

        for (int i = n - 1; i >= n - k; --i) {
            maxPoints += cardPoints[i];
        }

        if (n == k)
            return maxPoints;

        int currPoints = maxPoints;

        for (int i = 0; i < k; ++i) {
            currPoints += cardPoints[i] - cardPoints[n - k + i];
            maxPoints = max(maxPoints, currPoints);
        }

        return maxPoints;
    }
};

// Time Complexity - O(k)
// Auxiliary Space - O(1)
