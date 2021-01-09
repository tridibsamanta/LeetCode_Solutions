/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 438. Find All Anagrams in a String
~ Link      : https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> idx;

        int n = s.length(), k = p.length();

        unordered_map<char, int> ump;

        for (int i = 0; i < k; ++i) {
            ++ump[p[i]];
        }

        int cnt = ump.size();
        int i = 0, j = 0;

        while (j < n) {

            if (ump.find(s[j]) != ump.end()) {

                if (--ump[s[j]] == 0)
                    --cnt;
            }

            if ((j - i + 1) < k) {
                ++j;
            }
            else if ((j - i + 1) == k) {

                if (cnt == 0)
                    idx.emplace_back(i);

                if (ump.find(s[i]) != ump.end()) {
                    if (++ump[s[i]] == 1)
                        ++cnt;
                }

                ++i;
                ++j;
            }
        }

        return idx;
    }
};
