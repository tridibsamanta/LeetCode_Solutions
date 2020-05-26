/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1389. Create Target Array in the Given Order
~ Link      : https://leetcode.com/problems/create-target-array-in-the-given-order/
*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i = 0; i < index.size(); ++i) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};
