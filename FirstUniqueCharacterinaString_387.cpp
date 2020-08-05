/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 387. First Unique Character in a String
~ Link      : https://leetcode.com/problems/first-unique-character-in-a-string/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        pair<int, int> arr[26];
        for (int i = 0; s[i]; ++i) {
            (arr[s[i] - 'a'].first)++;
            arr[s[i] - 'a'].second = i;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (arr[i].first == 1)
                res = min(res, arr[i].second);
        }

        return ((res != INT_MAX) ? res : -1);
    }
};
