/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1103. Distribute Candies to People
~ Link      : https://leetcode.com/problems/distribute-candies-to-people/
*/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> res(num_people, 0);

        int t = 0;
        while (candies > 0) {

            res[t % num_people] += min(candies, t + 1);
            candies -= t + 1;
            ++t;
        }
        return res;
    }
};
