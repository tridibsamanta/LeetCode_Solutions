/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 472. Concatenated Words
~ Link      : https://leetcode.com/problems/concatenated-words/
*/

class Solution {
public:
    unordered_set<string> occurred;

    static bool compare(const string str1, const string str2) {
        return (str1.size() < str2.size());
    }

    bool isConcatenatedWord(string word) {
        int m = word.size();

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j])
                    continue;

                if (occurred.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[m];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();

        if (n < 3)
            return vector<string> {};

        sort(words.begin(), words.end(), compare);

        vector<string> res;
        occurred.insert(words[0]);

        for (int i = 1; i < n; ++i) {
            if (isConcatenatedWord(words[i]))
                res.emplace_back(words[i]);

            occurred.insert(words[i]);
        }

        return res;
    }
};

/*
~ Time Complexity - O(n * m^3)
~ Auxiliary Space - O(n * m)
~ where, n = words.size() & m = words[i].size()
*/
