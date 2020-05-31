/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 169. Majority Element
~ Link      : https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0, element = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0)
                element = nums[i];
            if (element == nums[i])
                ++count;
            else
                --count;
        }

        return element;
    }
};
