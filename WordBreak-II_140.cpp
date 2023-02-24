/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 140. Word Break II
~ Link      : https://leetcode.com/problems/word-break-ii/
*/

class Solution {
public:
    unordered_set<string> dict;
    vector<string> sentences;

    void wordBreakUtil(string s, int idx, vector<string> &curr) {
        if (idx == s.size()) {
            string currSentence = "";

            for (auto str : curr) {
                currSentence += str + ' ';
            }

            currSentence.pop_back();
            sentences.emplace_back(currSentence);

            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            string t = s.substr(idx, i - idx + 1);

            if (dict.count(t)) {
                curr.emplace_back(t);

                wordBreakUtil(s, i + 1, curr);

                curr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto str : wordDict) {
            dict.insert(str);
        }

        vector<string> curr;

        wordBreakUtil(s, 0, curr);

        return sentences;
    }
};

// Time Complexity - O(2^s.size() * s.size())
// Auxiliary Space - O(wordDict.size() * word[i].size())
