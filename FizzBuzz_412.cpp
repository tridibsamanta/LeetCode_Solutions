/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 412. Fizz Buzz
~ Link      : https://leetcode.com/problems/fizz-buzz/
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> fizzBuzz;

        for (int i = 1; i <= n; ++i) {

            if (i % 15 == 0)
                fizzBuzz.emplace_back("FizzBuzz");
            else if (i % 3 == 0)
                fizzBuzz.emplace_back("Fizz");
            else if (i % 5 == 0)
                fizzBuzz.emplace_back("Buzz");
            else
                fizzBuzz.emplace_back(to_string(i));
        }
        return fizzBuzz;
    }
};
