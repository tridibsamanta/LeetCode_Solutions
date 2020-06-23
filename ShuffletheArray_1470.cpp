/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1470. Shuffle the Array
~ Link      : https://leetcode.com/problems/shuffle-the-array/
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0, j = n; i < n; ++i, ++j){
            res.emplace_back(nums[i]);
            res.emplace_back(nums[j]);
        }
        return res;
    }
};
