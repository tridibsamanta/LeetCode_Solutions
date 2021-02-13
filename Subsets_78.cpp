/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 78. Subsets
~ Link      : https://leetcode.com/problems/subsets/
*/

/* Approach 1 (Recursive) */

class Solution {
public:
    void subsetsUtil(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

        ans.emplace_back(curr);

        for (int i = idx; i < nums.size(); ++i) {

            curr.emplace_back(nums[i]);

            subsetsUtil(i + 1, nums, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;
        vector<int> curr;

        subsetsUtil(0, nums, curr, ans);

        return ans;
    }
};


/* Approach 2 (Iterative) */

/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        int m = pow(2, n);

        for (int i = 0; i < m; ++i) {

            vector<int> curr;

            for (int j = 0; j < n; ++j) {

                if (i & (1 << j))
                    curr.emplace_back(nums[j]);
            }

            ans.emplace_back(curr);
        }

        return ans;
    }
};
*/
