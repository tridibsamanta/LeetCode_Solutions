/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 3. Longest Substring Without Repeating Characters
~ Link      : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    #define ALL_CHARS 256
    int lengthOfLongestSubstring(string s) {
        vector<int> lastOcc(ALL_CHARS, -1);
        int maxLength = 0, start = 0;
        for (int j = 0; j < s.size(); ++j) {
            start = max(start, lastOcc[s[j]] + 1);
            maxLength = max(maxLength, j - start + 1);
            lastOcc[s[j]] = j;
        }
        return maxLength;
    }
};
