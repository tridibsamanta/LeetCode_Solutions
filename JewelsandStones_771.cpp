/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 771. Jewels and Stones
~ Link      : https://leetcode.com/problems/jewels-and-stones/
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {

        unordered_set<char> uset;

        int ans = 0;

        for (char& ch : J)
            uset.insert(ch);

        for (char& key : S)
            if (uset.find(key) != uset.end())
                ans++;

        return ans;
    }
};
