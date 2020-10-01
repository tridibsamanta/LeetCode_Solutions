/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1528. Shuffle String
~ Link      : https://leetcode.com/problems/shuffle-string/
*/

/*
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        int n = s.length();

        if (n == 1)
            return s;

        map<int, char> mp;

        for (int i = 0; i < n; ++i) {
            mp[indices[i]] = s[i];
        }

        string res = "";

        for (auto i : mp) {
            res += i.second;
        }

        return res;
    }
};
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        string res = s;

        for (int i = 0; i < indices.size(); ++i)
            res[indices[i]] = s[i];

        return res;
    }
};
