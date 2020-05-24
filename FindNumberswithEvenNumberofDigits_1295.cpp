/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1295. Find Numbers with Even Number of Digits
~ Link      : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto itr: nums)
            count += (int)log10(itr) & 1;
        return count;
    }
};
