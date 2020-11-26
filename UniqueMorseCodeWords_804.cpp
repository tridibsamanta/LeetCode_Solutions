/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 804. Unique Morse Code Words
~ Link      : https://leetcode.com/problems/unique-morse-code-words/
*/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        int n = words.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> pattern;

        for (int i = 0; i < n; ++i) {

            string curr_pattern = "";

            for (int j = 0; j < words[i].size(); ++j)
                curr_pattern += code[words[i][j] - 'a'];

            pattern.insert(curr_pattern);
        }

        return pattern.size();
    }
};
