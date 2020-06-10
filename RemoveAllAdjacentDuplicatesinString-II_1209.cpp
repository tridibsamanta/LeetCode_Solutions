/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1209. Remove All Adjacent Duplicates in String II
~ Link      : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk = {{0, '#'}};
        for (int i = 0; i < s.length(); ++i) {
            if (stk.back().second != s[i])
                stk.push_back({1, s[i]});
            else if (++stk.back().first == k)
                stk.pop_back();
        }

        string res;
        for (int i = 0; i < stk.size(); ++i)
            res.append(stk[i].first, stk[i].second);

        return res;
    }
};
