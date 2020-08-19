/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 824. Goat Latin
~ Link      : https://leetcode.com/problems/goat-latin/
*/

class Solution {
public:
    string toGoatLatin(string S) {

    string res = "";
    int start = 0, wordCount = 1, n = S.length();

    for(int i = 0; i <= n; ++i) {

        if(S[i] == ' ' || i == n) {

            string word(S.begin() + start, S.begin() + i);

            if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e' || word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o' || word[0] == 'O' || word[0] == 'u' || word[0] == 'U')
                res += word + "ma";
            else
                res += word.substr(1) + word[0] + "ma";

            for(int k = 1; k <= wordCount; ++k)
                res += 'a';

            if(i != n)
                res += ' ';

            start = i + 1;
            ++wordCount;
        }
    }
    return res;
    }
};
