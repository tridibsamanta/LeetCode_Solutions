/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 560. Subarray Sum Equals K
~ Link      : https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> hm;

    int curr_sum = 0, count = 0;

    for(int i = 0; i < nums.size(); ++i) {
        curr_sum += nums[i];
        if (curr_sum == k)
            ++count;
        if (hm.find(curr_sum - k) != hm.end())
            count += hm[curr_sum - k];
        ++hm[curr_sum];
    }
    return count;
    }
};
