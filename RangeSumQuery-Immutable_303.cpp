/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 303. Range Sum Query - Immutable
~ Link      : https://leetcode.com/problems/range-sum-query-immutable/
*/

class NumArray {
public:
    vector<long long> pref;

    NumArray(vector<int>& nums) {
        pref.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return pref[right + 1] - pref[left];
    }
    // O(1)
};

/*
 ~ Time Complexity: O(n) -> NumArray(), O(1) -> sumRange()
 ~ Space Complexity: O(n) -> pref
   where n = nums.size()
*/
