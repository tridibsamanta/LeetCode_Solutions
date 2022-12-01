/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 28. Implement strStr()
~ Link      : https://leetcode.com/problems/implement-strstr/
*/

// Approach 1 (Brute-force)
/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        if (m > n)
            return -1;

        for (int i = 0; i + m <= n; ++i) {
            if (haystack[i] == needle[0]) {
                int idx = 0;

                while (idx < m) {
                    if (haystack[i + idx] != needle[idx])
                        break;

                    ++idx;
                }

                if (idx == m)
                    return i;
            }
        }

        return -1;
    }
};
*/
// Time Complexity - O(n * m)
// Auxiliary Space - O(1)

// Approach 2 (Using KMP Algorithm)

class Solution {
private:
    void computeLPS(string pattern, vector<int> &lps) {
        int n = pattern.size();

        lps[0] = 0;

        int i = 1, j = 0;

        while (i < n) {
            if (pattern[i] == pattern[j]) {
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
    }

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        vector<int> lps(m);
        vector<int> startIndex;

        computeLPS(needle, lps);

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            }

            if (j == m) {
                startIndex.emplace_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    ++i;
            }
        }

        return (startIndex.empty() ? -1 : startIndex[0]);
    }
};

// Time Complexity - O(n + m)
// Auxiliary Space - O(m)
