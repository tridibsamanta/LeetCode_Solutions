/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 860. Lemonade Change
~ Link      : https://leetcode.com/problems/lemonade-change/
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int n = bills.size();

        if (n == 0)
            return true;

        if (bills[0] == 10 || bills[0] == 20)
            return false;

        int count5 = 1, count10 = 0;

        for (int i = 1; i < n; ++i) {

            if (bills[i] == 5) {
                ++count5;
            }
            else if (bills[i] == 10) {
                if (count5 == 0) {
                    return false;
                }
                else {
                    --count5;
                    ++count10;
                }
            }
            else if (bills[i] == 20) {
                if (count10 > 0 && count5 > 0) {
                    --count10;
                    --count5;
                }
                else if (count5 >= 3) {
                    count5 -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
