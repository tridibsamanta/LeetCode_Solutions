/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1392. Longest Happy Prefix
~ Link      : https://leetcode.com/problems/longest-happy-prefix/
*/

class Solution {
public:

    vector<int> computeLPS(string str) {

        int n = str.length();

        vector<int> lps(n, 0);

        int j = 0, i = 1;

        while (i < n) {

            if (str[i] == str[j]) {
                lps[i] = j + 1;
                ++i;
                ++j;
            }
            else {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }

        return lps;
    }

    string longestPrefix(string s) {

        string res = "";

        int n = s.length();

        if (n <= 1)
            return res;

        vector<int> lps = computeLPS(s);

        if (lps[n - 1] == 0)
            return res;

        res = s.substr(0, lps[n - 1]);
        return res;
    }
};

// T.C. - O(n)
// S.C. - O(n)
