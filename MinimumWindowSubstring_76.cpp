/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 76. Minimum Window Substring
~ Link      : https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
    string minWindow(string str, string pat) {

        string res = "";

        if (str.length() < pat.length())
        return res;

        int patFreq[256];
        memset(patFreq, 0, sizeof(patFreq));

        int strFreq[256];
        memset(strFreq, 0, sizeof(strFreq));

        for (int i = 0; pat[i]; ++i)
            ++patFreq[pat[i]];

        int charCount = 0, currStartIdx = 0, minStartIdx = -1, minLength = INT_MAX;

        for (int i = 0; str[i]; ++i) {

            ++strFreq[str[i]];

            if (patFreq[str[i]] != 0 && strFreq[str[i]] <= patFreq[str[i]])
                ++charCount;

            if (charCount == pat.length()) {

                while (patFreq[str[currStartIdx]] == 0 || strFreq[str[currStartIdx]] > patFreq[str[currStartIdx]]) {

                    if (strFreq[str[currStartIdx]] > patFreq[str[currStartIdx]])
                        --strFreq[str[currStartIdx]];

                    ++currStartIdx;
                }

                int currLength = i - currStartIdx + 1;
                if (minLength > currLength) {
                    minLength = currLength;
                    minStartIdx = currStartIdx;
                }
            }
        }

        if (minStartIdx == -1)
            return res;

        res = str.substr(minStartIdx, minLength);
        return res;
    }
};
