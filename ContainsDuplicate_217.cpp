/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 217. Contains Duplicate
~ Link      : https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> hm;

        for (int i : nums) {

            if (hm[i] == 1)
                return true;
            else
                ++hm[i];
        }

        return false;
    }
};
