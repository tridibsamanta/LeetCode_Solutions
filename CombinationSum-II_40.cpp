/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 40. Combination Sum II
~ Link      : https://leetcode.com/problems/combination-sum-ii/
*/

// Approach 1

class Solution {
public:
    void combinationSum2Util(int idx, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {

            if (i > idx && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            curr.emplace_back(nums[i]);

            combinationSum2Util(i + 1, target - nums[i], nums, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        combinationSum2Util(0, target, candidates, curr, ans);

        return ans;
    }
};

// Approach 2 (Uses logn extra-time than approach 1 for storing elements in the set)
/*
class Solution {
public:
    void combinationSum2Util(int idx, int target, vector<int>& nums, vector<int>& curr, set<vector<int> >& ans) {

        if (target == 0) {
            ans.insert(curr);
            return;
        }

        if (idx == nums.size())
            return;

        if (nums[idx] <= target) {
            curr.emplace_back(nums[idx]);
            combinationSum2Util(idx + 1, target - nums[idx], nums, curr, ans);
            curr.pop_back();
        }

        combinationSum2Util(idx + 1, target, nums, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        set<vector<int> > ans;
        vector<int> curr;
        combinationSum2Util(0, target, candidates, curr, ans);

        vector<vector<int> > res;

        for (auto i : ans) {
            res.emplace_back(i);
        }

        return res;
    }
};
*/
