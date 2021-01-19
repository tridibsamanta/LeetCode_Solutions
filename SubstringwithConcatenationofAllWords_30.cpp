/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 30. Substring with Concatenation of All Words
~ Link      : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.size();
        int wlen = words[0].size();
        int k = wlen * words.size();

        if (n < k)
            return vector<int> {};

        vector<int> res;

        unordered_map<string, int> ump;

        for (int i = 0; i < words.size(); ++i) {
            ++ump[words[i]];
        }

        for (int i = 0; i <= (n - k); ++i) {

            unordered_map<string, int> check = ump;

            for (int j = i; j <= (i + k - wlen); j += wlen) {

                string currWord = s.substr(j, wlen);

                if (ump.find(currWord) != ump.end()) {

                    if (--check[currWord] < 0)
                        break;

                    if (check[currWord] == 0) {
                        check.erase(currWord);

                        if (check.size() == 0)
                            res.emplace_back(i);
                    }
                }
                else
                    break;
            }
        }

        return res;
    }
};
