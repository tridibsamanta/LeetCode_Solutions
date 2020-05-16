/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1047. Remove All Adjacent Duplicates In String
~ Link      : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (int i = 0; i < S.size(); ++i) {
            if (res.size() > 0 && res.back() == S[i])
                res.pop_back();
            else
                res.push_back(S[i]);
        }
        return res;
    }
};
