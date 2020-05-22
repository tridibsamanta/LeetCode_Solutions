/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1431. Kids With the Greatest Number of Candies
~ Link      : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        vector<bool> checkLuckyKid;

        int max = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); ++i)
            checkLuckyKid.push_back((candies[i] + extraCandies) >= max);

        return checkLuckyKid;
    }
};
