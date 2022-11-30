/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 402. Remove K Digits
~ Link      : https://leetcode.com/problems/remove-k-digits/
*/

/* Approach 1 : Using DP */
/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (k == n)
            return "0";

        vector<vector<int> > rightOccIdx(n + 1, vector<int> (10, -1));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                rightOccIdx[i][j] = rightOccIdx[i + 1][j];
            }

            rightOccIdx[i][num[i] - '0'] = i;
        }

        string res = "";

        int numIdx = 0, remDeletionCnt = k;

        for (int i = 0; i < n - k; ++i) {
            for (int d = 0; d < 10; ++d) {
                if (rightOccIdx[numIdx][d] == -1)
                    continue;

                int currDeletionCnt = rightOccIdx[numIdx][d] - numIdx;

                if (currDeletionCnt > remDeletionCnt)
                    continue;

                res.push_back('0' + d);

                if (res.size() == 1 && res.front() == '0')
                    res.pop_back();

                remDeletionCnt -= currDeletionCnt;
                numIdx = rightOccIdx[numIdx][d] + 1;

                break;
            }
        }

        return (res.empty() ? "0" : res);
    }
};
*/
// Time Complexity - O((n - k) * 10) = O(n)
// Auxiliary Space - O(n * 10) = O(n)

/* Approach 2 : Using Monotonic Stack */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (k == n)
            return "0";

        stack<char> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && stk.top() > num[i] && k > 0) {
                stk.pop();
                --k;
            }

            if (stk.empty() && num[i] == '0')
                continue;

            stk.push(num[i]);
        }

        while (!stk.empty() && k > 0) {
            stk.pop();
            --k;
        }

        if (stk.empty())
            return "0";

        string res = "";

        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
