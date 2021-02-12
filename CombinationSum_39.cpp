/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 39. Combination Sum
~ Link      : https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    void combinationSumUtil(int idx, int target, vector<int>& nums, vector<int>& curr, vector<vector<int> >& ans) {

        // If we have traversed all elements
        if (idx == nums.size()) {

            // If all considerations till now adds up to form given target,
            // then the sequence in 'curr' is a valid combination
            // if (target == 0)
            //     ans.emplace_back(curr);

            return;
        }

        // If at any index we have formed our given sum,
        // then the sequence in 'curr' is a valid combination
        if (target == 0) {
            ans.emplace_back(curr);
            return;
        }

        // If current element is greater than target,
        // then all all succeeding elements would be greater than target,
        // as the given array has been sorted
        if (nums[idx] > target) {
            return;
        }

        // If current element is <= target, then
        //    ~ Case 1: Include current element
        else if (nums[idx] <= target) {
            curr.emplace_back(nums[idx]);
            combinationSumUtil(idx, target - nums[idx], nums, curr, ans);
            curr.pop_back();
        }

        //    ~ Case 2: Dont include current element
        combinationSumUtil(idx + 1, target, nums, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // We sort the given array in non-decreasing order,
        // so that once we reach an element greater than the current target,
        // we can return, as because all succeeding elements would be greater than the current target.


        sort(candidates.begin(), candidates.end());

        vector<vector<int> > ans;
        vector<int> curr;
        combinationSumUtil(0, target, candidates, curr, ans);
        return ans;
    }
};


// class Solution {
// public:
//     void combinationSumUtil(int idx, int target, vector<int>& nums, vector<int>& curr, vector<vector<int> >& ans) {

//         if (idx == nums.size()) {
//             if (target == 0)
//                 ans.emplace_back(curr);
//             return;
//         }

//         /*
//             If current element is <= target, then
//                 ~ Case 1: Include current element
//                 ~ Case 2: Dont include current element
//             Else if, current element is > target, then
//                 ~ Case 1: Dont include current element
//         */

//         if (nums[idx] <= target) {
//             curr.emplace_back(nums[idx]);
//             combinationSumUtil(idx, target - nums[idx], nums, curr, ans);
//             curr.pop_back();
//         }

//         combinationSumUtil(idx + 1, target, nums, curr, ans);
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

//         vector<vector<int> > ans;
//         vector<int> curr;
//         combinationSumUtil(0, target, candidates, curr, ans);
//         return ans;
//     }
// };
