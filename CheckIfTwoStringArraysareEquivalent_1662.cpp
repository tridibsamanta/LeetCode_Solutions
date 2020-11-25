/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1662. Check If Two String Arrays are Equivalent
~ Link      : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string str1 = "", str2 = "";

        for (int i = 0; i < word1.size(); ++i)
            str1 += word1[i];

        for (int i = 0; i < word2.size(); ++i)
            str2 += word2[i];

        return str1 == str2;
    }
};
