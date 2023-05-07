/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1456. Maximum Number of Vowels in a Substring of Given Length
~ Link      : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/

class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int vowelCnt = 0, startIdx = 0, currVowelCnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i - startIdx + 1 > k) {
                currVowelCnt -= isVowel(s[startIdx]);
                ++startIdx;
            }

            if (isVowel(s[i]))
                vowelCnt = max(vowelCnt, ++currVowelCnt);
        }

        return vowelCnt;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
