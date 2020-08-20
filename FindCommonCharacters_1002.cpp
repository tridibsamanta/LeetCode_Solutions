/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1002. Find Common Characters
~ Link      : https://leetcode.com/problems/find-common-characters/
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        int n = A.size();

        int freq[n][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                freq[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < A[i].length(); ++j) {
                ++freq[i][A[i][j] - 'a'];
            }
        }

        vector<string> res;

        for (int i = 0; i < 26; ++i) {
            int minFreq = INT_MAX, j;
            for (j = 0; j < n; ++j) {
                if (!freq[j][i])
                    break;
                else
                    minFreq = min(minFreq, freq[j][i]);
            }
            if (j == n) {
                while(minFreq--) {
                    res.emplace_back(string(1, i + 'a'));
                }
            }
        }

        return res;
    }
};
