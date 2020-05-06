/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1365. How Many Numbers Are Smaller Than the Current Number
~ Link      : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> freq(nums.size());
        vector<int> sortedNums(nums);

        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < nums.size(); ++i) {
            auto idx = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]);
            freq[i] = idx - sortedNums.begin();
        }
        return freq;
    }
};
