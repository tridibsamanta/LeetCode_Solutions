/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1512. Number of Good Pairs
~ Link      : https://leetcode.com/problems/number-of-good-pairs/
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int n = nums.size(), good_pairs = 0;

        if (n < 2)
            return 0;

        unordered_map<int, int> ump;

        for (int i = 0; i < n; ++i)
            good_pairs += ump[nums[i]]++;

        return good_pairs;
    }
};
