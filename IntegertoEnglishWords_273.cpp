/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 273. Integer to English Words
~ Link      : https://leetcode.com/problems/integer-to-english-words/
*/

class Solution {
public:
    vector<string> words1 = {"Zero",
                            "One",
                            "Two",
                            "Three",
                            "Four",
                            "Five",
                            "Six",
                            "Seven",
                            "Eight",
                            "Nine",
                            "Ten",
                            "Eleven",
                            "Twelve",
                            "Thirteen",
                            "Fourteen",
                            "Fifteen",
                            "Sixteen",
                            "Seventeen",
                            "Eighteen",
                            "Nineteen"};

    vector<string> words2 = {"Twenty",
                             "Thirty",
                             "Forty",
                             "Fifty",
                             "Sixty",
                             "Seventy",
                             "Eighty",
                             "Ninety"};

    string numberToWordsUtil(int num) {
        if (num >= 1000000000)
            return numberToWordsUtil(num / 1000000000) + " Billion"
                    + numberToWordsUtil(num % 1000000000);

        else if (num >= 1000000)
            return numberToWordsUtil(num / 1000000) + " Million"
                    + numberToWordsUtil(num % 1000000);

        else if (num >= 1000)
            return numberToWordsUtil(num / 1000) + " Thousand"
                    + numberToWordsUtil(num % 1000);

        else if (num >= 100)
            return numberToWordsUtil(num / 100) + " Hundred"
                    + numberToWordsUtil(num % 100);

        else if (num >= 20)
            return " " + words2[num / 10 - 2] + numberToWordsUtil(num % 10);

        else if (num >= 1)
            return " " + words1[num];

        return "";
    }

    string numberToWords(int num) {
        if (num == 0)
            return words1[num];

        string res = numberToWordsUtil(num);
        res = res.substr(1);

        return res;
    }
};

// T.C. - O(log num)
// S.C. - O(1)
