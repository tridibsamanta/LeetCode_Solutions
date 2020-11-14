/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1614. Maximum Nesting Depth of the Parentheses
~ Link      : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/

class Solution {
public:
    int maxDepth(string s) {

        int depth = 0, currDepth = 0;

        for (int i = 0; s[i]; ++i) {
            if (s[i] == '(') {
                ++currDepth;
                depth = max(depth, currDepth);
            }
            else if (s[i] == ')')
                --currDepth;
        }

        return depth;
    }
};
