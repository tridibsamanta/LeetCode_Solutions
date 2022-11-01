/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 22. Generate Parentheses
~ Link      : https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    void generateParenthesisUtil(int openCount, int closeCount, int n,
                                 string curr, vector<string> &res) {

        if (curr.size() == 2 * n) {
            res.emplace_back(curr);
            return;
        }

        if (openCount < n) {
            curr.push_back('(');
            generateParenthesisUtil(openCount + 1, closeCount, n, curr, res);
            curr.pop_back();
        }

        if (closeCount < openCount) {
            curr.push_back(')');
            generateParenthesisUtil(openCount, closeCount + 1, n, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";

        generateParenthesisUtil(0, 0, n, curr, res);

        return res;
    }
};

// Time Complexity - O(4^n / √n)
// Space Complexity - O(4^n / √n)
