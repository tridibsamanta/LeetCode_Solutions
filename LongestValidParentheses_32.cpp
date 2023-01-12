/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 32. Longest Valid Parentheses
~ Link      : https://leetcode.com/problems/longest-valid-parentheses/
*/

/* Approach 1 : Bottom-Up (Tabulation) DP */
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        if (n < 2)
            return 0;

        vector<int> dp(n, 0);
        int len = 0;

        for (int i = 1; i < n; ++i) {

            if (s[i] == ')') {

                if (s[i - 1] == '(') {
                    dp[i] = 2 + (i > 1 ? dp[i - 2] : 0);
                }
                else {
                    int openIdx = i - dp[i - 1] - 1;

                    if (openIdx >= 0 && s[openIdx] == '(')
                        dp[i] = 2 + dp[i - 1] + (openIdx > 0 ? dp[openIdx - 1] : 0);
                }

                len = max(len, dp[i]);
            }
        }

        return len;
    }
};
*/
// Time Complexity - O(n)
// Auxiliary Space - O(n)

/* Approach 2 : Using Stack */
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        if (n < 2)
            return 0;

        stack<int> stk;
        stk.push(-1);

        int len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                stk.pop();

                if (stk.empty())
                    stk.push(i);
                else
                    len = max(len, i - stk.top());
            }
        }

        return len;
    }
};
*/
// Time Complexity - O(n)
// Auxiliary Space - O(n)

/* Approach 3 : Using constant extra space */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        if (n < 2)
            return 0;

        int len = 0;
        int openCount = 0, closeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++openCount;
            else if (s[i] == ')')
                ++closeCount;

            if (openCount == closeCount)
                len = max(len, 2 * closeCount);
            else if (closeCount > openCount)
                openCount = closeCount = 0;
        }

        openCount = closeCount = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(')
                ++openCount;
            else if (s[i] == ')')
                ++closeCount;

            if (openCount == closeCount)
                len = max(len, 2 * openCount);
            else if (openCount > closeCount)
                openCount = closeCount = 0;
        }

        return len;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(1)
