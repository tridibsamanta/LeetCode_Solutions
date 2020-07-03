/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1309. Decrypt String from Alphabet to Integer Mapping
~ Link      : https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
*/

class Solution {
public:
    string freqAlphabets(string s) {

        string res = "";

        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] != '#' ) {
                char c = 96 + s[i] - '0';
                res += c;
            }
            else {
                char c = 96 + s[i - 1] - '0' + (s[i - 2] - '0') * 10;
                res += c;
                i -= 2;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
