/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 90. Subsets II
~ Link      : https://leetcode.com/problems/subsets-ii/
*/

class Solution {
public:
    void subsetsWithDupUtil(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

        ans.emplace_back(curr);

        for (int i = idx; i < nums.size(); ++i) {

            if (i > idx && nums[i] == nums[i - 1])
                continue;

            curr.emplace_back(nums[i]);

            subsetsWithDupUtil(i + 1, nums, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;
        vector<int> curr;

        subsetsWithDupUtil(0, nums, curr, ans);

        return ans;
    }
};

// T.C. - O(N * 2^N), to generate all subsets and then copy them into the output list ans.
// S.C. - O(N * 2^N), to store all the 2^N subsets, each having maximum length of N.
