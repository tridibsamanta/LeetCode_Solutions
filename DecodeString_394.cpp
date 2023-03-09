/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 394. Decode String
~ Link      : https://leetcode.com/problems/decode-string/
*/

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> stk;
        vector<pair<string, int> > group;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                string freq = "";

                while (i < s.size()) {
                    if (!(s[i] >= '0' && s[i] <= '9')) {
                        --i;
                        break;
                    }

                    freq.push_back(s[i++]);
                }

                group.push_back({"", stoi(freq)});
            }
            else if (s[i] == '[') {
                stk.push(s[i]);
            }
            else if (s[i] == ']') {
                stk.pop();

                string curr = group.back().first;
                int currFreq = group.back().second;

                group.pop_back();

                if (stk.empty()) {
                    while (currFreq--) {
                        res += curr;
                    }
                }
                else {
                    while (currFreq--) {
                        group.back().first += curr;
                    }
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                if (stk.empty())
                    res.push_back(s[i]);
                else {
                    group.back().first.push_back(s[i]);
                }
            }
        }

        return res;
    }
};

// Time Complexity - O(n^2 * 300)
// Auxiliary Space - O(n * 300)
