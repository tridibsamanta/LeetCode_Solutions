/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 520. Detect Capital
~ Link      : https://leetcode.com/problems/detect-capital/
*/

class Solution {
public:
    bool detectCapitalUse(string word) {

        if (word.length() == 0 || word.length() == 1)
            return true;

        if (islower(word[0])) {
            for (int i = 1; i < word.length(); ++i)
                if (isupper(word[i]))
                    return false;
        }
        else {
            if (islower(word[1])) {
                for (int i = 2; i < word.length(); ++i)
                    if (isupper(word[i]))
                        return false;
            }
            else {
                for (int i = 2; i < word.length(); ++i)
                    if (islower(word[i]))
                        return false;
            }
        }

        return true;
    }
};
