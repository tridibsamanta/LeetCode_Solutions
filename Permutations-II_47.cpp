/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 47. Permutations II
~ Link      : https://leetcode.com/problems/permutations-ii/
*/

class Solution {
public:
    void permuteUniqueUtil(vector<int>& nums, vector<bool>& available, vector<int>& curr, vector<vector<int>>& ans) {

        if (curr.size() == nums.size()) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {

            /*
                If i > 0 it means that current element maybe a duplicate inclusion.
                If i == 0, even if current element has duplicates, we allow the first time inclusion of it,
                hence we check only when i > 0.

                nums[i] == nums[i - 1], as the array is sorted, the duplicates will be placed together,
                hence checking if current element, matches with the previous element, it is a duplicate.

                available[i - 1] == true, if previous element is available, it mean there has been some permutation before
                where we have taken the previous element along with the current element, hence we skip it now,
                to avoid duplicate permutation.
                If available[i - 1] == false, it means previous element is present in the current permutation and
                hence we can include the current element in the permutation,
                as one permutation is allowed considering all the duplicates, at their original indices.

                Ex. [1, 1, 2] -> We include [1, 1, 2] once.
                But again when the second 1 wants to become the first element we don't allow,
                because then available[0] = true,
                which means we have previously considered the permutation where 1 is the first element.
            */
            if (available[i] == false || i > 0 && nums[i] == nums[i - 1] && available[i - 1] == true)
                continue;

            curr.emplace_back(nums[i]);
            available[i] = false;

            permuteUniqueUtil(nums, available, curr, ans);

            curr.pop_back();
            available[i] = true;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> available(nums.size(), true);

        permuteUniqueUtil(nums, available, curr, ans);

        return ans;
    }
};
