/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 1313. Decompress Run-Length Encoded List
~ Link      : https://leetcode.com/problems/decompress-run-length-encoded-list/
*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {

        vector<int> rle;

        for (int i = 0; i < (nums.size() - 1); i += 2)
            for (int j = 0; j < nums[i]; ++j)
                rle.push_back(nums[i + 1]);

        return rle;
    }
};
