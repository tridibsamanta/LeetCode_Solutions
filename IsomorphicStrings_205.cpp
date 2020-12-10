/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 205. Isomorphic Strings
~ Link      : https://leetcode.com/problems/isomorphic-strings/
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;

        char s_map[128];
        char t_map[128];

        memset(s_map, 0, sizeof(s_map));
        memset(t_map, 0, sizeof(t_map));

        for (int i = 0; s[i]; ++i) {

            if (s_map[s[i]] == 0 && t_map[t[i]] == 0) {
                s_map[s[i]] = t[i];
                t_map[t[i]] = s[i];
            }
            else {
                if (s_map[s[i]] != t[i] || t_map[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};
