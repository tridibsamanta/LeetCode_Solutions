/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 521. Longest Uncommon Subsequence I
~ Link      : https://leetcode.com/problems/longest-uncommon-subsequence-i/
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
        int res = -1;
        if (!a.compare(b))
            return res;
        else
            res = max(a.size(), b.size());
        return res;
    }
};
