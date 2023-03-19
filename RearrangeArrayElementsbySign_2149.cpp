/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2149. Rearrange Array Elements by Sign
~ Link      : https://leetcode.com/problems/rearrange-array-elements-by-sign/
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int posIdx = 0, negIdx = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[posIdx] = nums[i];
                posIdx += 2;
            }
            else {
                res[negIdx] = nums[i];
                negIdx += 2;
            }
        }

        return res;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
