/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2390. Removing Stars From a String
~ Link      : https://leetcode.com/problems/removing-stars-from-a-string/
*/

/* Approach 1 (Using Stack) */
/*
class Solution {
public:
    string removeStars(string s) {
        vector<char> stk;

        for (char c : s) {
            if (c != '*')
                stk.emplace_back(c);
            else
                stk.pop_back();
        }

        return string (stk.begin(), stk.end());
    }
};
*/
// Time Complexity - O(n)
// Auxiliary Space - O(n)

/* Approach 2 (Using Two-pointers) */

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int charPtr = n - 1, starPtr = n - 1;

        string res = "";

        while (starPtr >= 0) {
            if (s[starPtr] == '*') {

                while (charPtr > starPtr) {
                    if (s[charPtr] != '*')
                        res.push_back(s[charPtr]);

                    --charPtr;
                }

                while (s[charPtr] == '*') {
                    --charPtr;
                }

                // remove current non-star char
                --charPtr;
            }

            --starPtr;
        }

        while (charPtr >= 0) {
            res.push_back(s[charPtr--]);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
