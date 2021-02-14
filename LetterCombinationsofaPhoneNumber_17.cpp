/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 17. Letter Combinations of a Phone Number
~ Link      : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

// Approach 1 (Backtracking)

class Solution {
public:
    map<char, string> keys {{'2', "abc"},
                            {'3', "def"},
                            {'4', "ghi"},
                            {'5', "jkl"},
                            {'6', "mno"},
                            {'7', "pqrs"},
                            {'8', "tuv"},
                            {'9', "wxyz"}};

    void letterCombinationsUtil(int idx, string& digits, string& curr, vector<string>& ans) {

        if (curr.length() == digits.length()) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = idx; i < digits.length(); ++i) {

            for (int j = 0; j < keys[digits[i]].length(); ++j) {

                curr.push_back(keys[digits[i]][j]);

                letterCombinationsUtil(i + 1, digits, curr, ans);

                curr.pop_back();
            }
        }

    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string curr = "";

        if (digits.length() == 0)
            return ans;

        letterCombinationsUtil(0, digits, curr, ans);

        return ans;

    }
};

// T.C. - O(3^N * 4^M), where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.
// S.C. - O(3^N * 4^M), the total number of possible letter combinations is 3^N * 4^M, hence that much amount of storage space is required.

// Approach 2 (BFS using queue)
/*
class Solution {
public:
    map<char, string> keys {{'2', "abc"},
                            {'3', "def"},
                            {'4', "ghi"},
                            {'5', "jkl"},
                            {'6', "mno"},
                            {'7', "pqrs"},
                            {'8', "tuv"},
                            {'9', "wxyz"}};

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.length() == 0)
            return ans;

        queue<string> q;
        q.push("");

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            if (curr.length() == digits.length())
                ans.emplace_back(curr);
            else
                for (auto letter : keys[digits[curr.length()]])
                    q.push(curr + letter);
        }

        return ans;
    }
};
*/
// T.C. - O(3^N * 4^M)
// S.C. - O(3^N * 4^M)
