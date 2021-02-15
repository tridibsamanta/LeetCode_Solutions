/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 46. Permutations
~ Link      : https://leetcode.com/problems/permutations/
*/

/* Approach 1 */

class Solution {
public:
    void permuteUtil(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

        if (curr.size() == nums.size()) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {

            if (find(curr.begin(), curr.end(), nums[i]) != curr.end())
                continue;

            curr.emplace_back(nums[i]);

            permuteUtil(nums, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        permuteUtil(nums, curr, ans);

        return ans;
    }
};

// T.C. - O(N * N!)
// S.C. - O(N * N!)

/* Approach 2 */

/*
class Solution {
public:
    void permuteUtil(int idx, vector<int>& nums, vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.emplace_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {

            swap(nums[i], nums[idx]);

            permuteUtil(idx + 1, nums, ans);

            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        permuteUtil(0, nums, ans);

        return ans;
    }
};
*/

// T.C. - O(N * N!)
// S.C. - O(N * N!)
