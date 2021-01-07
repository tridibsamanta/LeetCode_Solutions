/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 43. Multiply Strings
~ Link      : https://leetcode.com/problems/multiply-strings/
*/

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.length(), n2 = num2.length();

        vector<int> res(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; --i) {

            for (int j = n2 - 1; j >= 0; --j) {

                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        string prod = "";

        int i = 0;
        while (i < res.size() && res[i] == 0) {
            ++i;
        }

        while (i < res.size()) {
            prod.push_back(res[i++] + '0');
        }

        return prod;
    }
};
