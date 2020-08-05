/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 383. Ransom Note
~ Link      : https://leetcode.com/problems/ransom-note/
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int hash[26];
        memset(hash, 0, sizeof(hash));

        for (int i = 0; magazine[i]; ++i)
            hash[magazine[i] - 'a']++;

        for (int i = 0; ransomNote[i]; ++i)
            if (--hash[ransomNote[i] - 'a'] < 0)
                return false;

        return true;
    }
};
