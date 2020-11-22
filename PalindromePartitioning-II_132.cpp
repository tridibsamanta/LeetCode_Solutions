/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 132. Palindrome Partitioning II
~ Link      : https://leetcode.com/problems/palindrome-partitioning-ii/
*/

class Solution {
public:
    bool palindrome[2001][2001];

    int minCut(string s) {

        int n = s.length();

        for (int i = 0; i < n; ++i) {
            palindrome[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])
                palindrome[i][i + 1] = true;
        }

        for (int currLen = 3; currLen <= n; ++currLen) {

            for (int startIdx = 0; startIdx <= n - currLen; ++startIdx) {

                int endIdx = startIdx + currLen - 1;

                if (s[startIdx] == s[endIdx] && palindrome[startIdx + 1][endIdx - 1])
                    palindrome[startIdx][endIdx] = true;
            }
        }

        int minCuts[n];

        for (int i = 0; i < n; ++i) {

            int currCuts = INT_MAX;

            if (palindrome[0][i])
                minCuts[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (palindrome[j + 1][i] && currCuts > minCuts[j] + 1)
                        currCuts = minCuts[j] + 1;
                }
                minCuts[i] = currCuts;
            }
        }

        return minCuts[n - 1];
    }
};
