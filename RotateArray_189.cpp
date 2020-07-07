/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 189. Rotate Array
~ Link      : https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> res;

        k = k % nums.size();

        for (int i = nums.size() - k; i < nums.size(); ++i)
            res.emplace_back(nums[i]);

        for (int i = 0; i < nums.size() - k; ++i)
            res.emplace_back(nums[i]);

        nums = res;
    }
};

// Alternate Approach
/*
class Solution {
private:
    void reverse(vector<int> &nums, int s, int e) {
        while (s < e) {
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            ++s;
            --e;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
*/
