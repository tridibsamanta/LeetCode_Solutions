/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 354. Russian Doll Envelopes
~ Link      : https://leetcode.com/problems/russian-doll-envelopes/
*/

// Sorting + DP + Binary Search Approach

class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        if (n <= 1)
            return n;

        sort(envelopes.begin(), envelopes.end(), comparator);

        vector<int> dp;
        dp.emplace_back(envelopes[0][1]);

        for (int i = 1; i < n; ++i) {

            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);

            if (itr == dp.end())
                dp.emplace_back(envelopes[i][1]);
            else
                *itr = envelopes[i][1];
        }

        return dp.size();
    }
};

// T.C. - O(nlogn)
// S.C. - O(n)

// Sorting + DP Approach
/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        if (n <= 1)
            return n;

        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(n, 1);

        int maxCnt = 1;

        for (int i = 1; i < n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1])
                    dp[i]  = max(dp[i] , dp[j] + 1);
            }

            maxCnt = max(maxCnt, dp[i]);
        }

        return maxCnt;
    }
};
*/
// T.C. - O(n^2)
// S.C. - O(n)
