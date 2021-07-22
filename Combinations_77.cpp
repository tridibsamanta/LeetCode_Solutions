/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 77. Combinations
~ Link      : https://leetcode.com/problems/combinations/
*/

class Solution {
public:
    void combineUtil(int curr, int k, int n, vector<int> &currCombination, vector<vector<int>> &ans) {

        if (currCombination.size() == k) {
            ans.emplace_back(currCombination);
            return;
        }

        for (int i = curr; i <= n; ++i) {

            currCombination.emplace_back(i);
            combineUtil(i + 1, k, n, currCombination, ans);
            currCombination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> currCombination;

        combineUtil(1, k, n, currCombination, ans);

        return ans;
    }
};
