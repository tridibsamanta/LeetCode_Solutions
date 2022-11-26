/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1249. Minimum Remove to Make Valid Parentheses
~ Link      : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

/* Approach 1 : (Using Auxiliary Stack) */
/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        stack<int> openIndex;

        for (int i = 0; i < n; ++i) {
            if (openIndex.empty() && s[i] == ')')
                s[i] = '#';
            else if (s[i] == ')')
                openIndex.pop();
            else if (s[i] == '(')
                openIndex.push(i);
        }

        while (!openIndex.empty()) {
            s[openIndex.top()] = '#';
            openIndex.pop();
        }

        string validStr = "";

        for (char c : s) {
            if (c == '#')
                continue;

            validStr.push_back(c);
        }

        return validStr;
    }
};
*/
// Time Complexity - O(n)
// Auxiliary Space - O(n)

/* Approach 2 : (Using constant extra space) */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        // considering each prefix of string s
        int openCount = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++openCount;
            else if (openCount == 0 && s[i] == ')')
                s[i] = '#';
            else if (s[i] == ')')
                --openCount;
        }

        // considering each suffix of string s
        int closeCount = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')')
                ++closeCount;
            else if (closeCount == 0 && s[i] == '(')
                s[i] = '#';
            else if (s[i] == '(')
                --closeCount;
        }

        string validStr = "";

        for (char c : s) {
            if (c == '#')
                continue;

            validStr.push_back(c);
        }

        return validStr;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
