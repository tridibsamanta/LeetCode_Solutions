/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1370. Increasing Decreasing String
~ Link      : https://leetcode.com/problems/increasing-decreasing-string/
*/

class Solution {
public:
    string sortString(string s) {

        int n = s.length();

        if (n <= 1)
            return s;

        string res = "";
        int res_len = 0;

        vector<int> freq(26, 0);

        for (int i = 0; s[i]; ++i)
            freq[s[i] - 'a']++;

        while (res_len != n) {

            for (int i = 0; i < 26; ++i) {
                if (freq[i] > 0) {
                    res += ('a' + i);
                    --freq[i];
                    ++res_len;
                }
            }

            for (int i = 25; i >= 0; --i) {
                if (freq[i] > 0) {
                    res += ('a' + i);
                    --freq[i];
                    ++res_len;
                }
            }
        }

        return res;
    }
};
