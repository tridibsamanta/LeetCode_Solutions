/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 227. Basic Calculator II
~ Link      : https://leetcode.com/problems/basic-calculator-ii/
*/

/* Approach 1 : (Using Stack) */
/*
class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int result = 0, currNum = 0;
        char sign = '+';

        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i]))
                currNum = (currNum * 10) + (s[i] - '0');

            if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
                if (sign == '+')
                    stk.push(currNum);
                else if (sign == '-')
                    stk.push(-currNum);
                else if (sign == '*') {
                    int stackTop = stk.top();
                    stk.pop();
                    stk.push(stackTop * currNum);
                }
                else if (sign == '/') {
                    int stackTop = stk.top();
                    stk.pop();
                    stk.push(stackTop / currNum);
                }

                sign = s[i];
                currNum = 0;
            }
        }

        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
*/
// Time Complexity - O(n)
// Space Complexity - O(1)

/* Approach 2 : (Using constant extra space) */

class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        char sign = '+';
        int result = 0, currNum = 0, lastNum = 0;

        for (int i = 0; i < n; ++i) {

            if (isdigit(s[i])) {
                currNum = (currNum * 10) + (s[i] - '0');
            }

            if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNum;
                    lastNum = (sign == '+') ? currNum : -currNum;
                }
                else if (sign == '*') {
                    lastNum *= currNum;
                }
                else if (sign == '/') {
                    lastNum /= currNum;
                }

                sign = s[i];
                currNum = 0;
            }
        }

        result += lastNum;
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
