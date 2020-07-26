/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 917. Reverse Only Letters
~ Link      : https://leetcode.com/problems/reverse-only-letters/
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {

        int len = S.length();
        int l = 0, r = len - 1;

        while (l < r) {
            if (!((S[l] >= 'a' && S[l] <= 'z') || (S[l] >= 'A' && S[l] <= 'Z')))
                ++l;
            else if (!((S[r] >= 'a' && S[r] <= 'z') || (S[r] >= 'A' && S[r] <= 'Z')))
                --r;
            else {
                swap(S[l], S[r]);
                ++l; --r;
            }
        }
        return S;
    }
};

/* Alternative Approach */
/*
class Solution {
public:
    string reverseOnlyLetters(string S) {

        string res = "";

        int j = S.length() - 1;

        for (int i = 0; S[i]; ++i) {
            if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
                while(!((S[j] >= 'A' && S[j] <= 'Z') || (S[j] >= 'a' && S[j] <= 'z')))
                    --j;
                res += S[j--];
            }
            else
                res += S[i];
        }

        return res;
    }
};
*/
