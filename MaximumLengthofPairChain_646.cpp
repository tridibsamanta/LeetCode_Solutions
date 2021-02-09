/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 646. Maximum Length of Pair Chain
~ Link      : https://leetcode.com/problems/maximum-length-of-pair-chain/
*/

// Approach 1 (Sort + DP)
/*
class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), comparator);

        vector<int> dp(n, 1);

        int maxCnt = 1;

        for (int i = 1; i < n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            maxCnt = max(maxCnt, dp[i]);
        }

        return maxCnt;
    }
};
*/

// T.C. - O(n*n)
// S.C. - O(n)

// Approach 2 (Using sort)

class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), comparator);

        int prev = pairs[0][1], maxCnt = 1;

        for (int i = 1; i < n; ++i) {

            if (pairs[i][0] > prev) {
                ++maxCnt;
                prev = pairs[i][1];
            }
        }

        return maxCnt;
    }
};

// T.C. - O(nlogn)
// S.C. - O(1)
