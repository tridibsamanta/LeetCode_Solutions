/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 424. Longest Repeating Character Replacement
~ Link      : https://leetcode.com/problems/longest-repeating-character-replacement/
*/

/*
class Solution {
public:
    int getSameCharLongestSubstringLen(char c, string s, int k) {
        int n = s.size(), i = 0, j = 0, maxLen = 0;

        while (j < n) {
            if (s[j] != c)
                --k;

            if (k >= 0) {
                maxLen = max(maxLen, j - i + 1);
            }
            else if (k < 0) {
                while (i <= j && k < 0) {
                    if (s[i] != c)
                        ++k;

                    ++i;
                }
            }

            ++j;
        }

        return maxLen;
    }

    int characterReplacement(string s, int k) {
        int maxLen = 0;

        for (char c = 'A'; c <= 'Z'; ++c) {
            int currLen = getSameCharLongestSubstringLen(c, s, k);
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};
*/
// Time Complexity - O(26 * n) = O(n)
// Space Complexity - O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int startIdx = 0, maxLen = 0, maxSameCnt = 0;

        for (int endIdx = 0; endIdx < n; ++endIdx) {
            ++freq[s[endIdx] - 'A'];

            maxSameCnt = max(maxSameCnt, freq[s[endIdx] - 'A']);

            while (endIdx - startIdx + 1 - maxSameCnt > k) {
                --freq[s[startIdx] - 'A'];
                ++startIdx;
            }

            maxLen = max(maxLen, endIdx - startIdx + 1);
        }

        return maxLen;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(26) = O(1)
