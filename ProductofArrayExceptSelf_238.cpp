/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 238. Product of Array Except Self
~ Link      : https://leetcode.com/problems/product-of-array-except-self/
*/

/* Approach 1 */
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> left_prods(n, 1);
        vector<int> right_prods(n, 1);

        for (int i = 1; i < n; ++i)
            left_prods[i] = nums[i - 1] * left_prods[i - 1];

        for (int i = n - 2; i >= 0; --i)
            right_prods[i] = nums[i + 1] * right_prods[i + 1];

        for (int i = 0; i < n; ++i)
            nums[i] = left_prods[i] * right_prods[i];

        return nums;
    }
};
*/

/* Approach 2 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(n, 1);

        for (int i = 1; i < n; ++i)
            res[i] = nums[i - 1] * res[i - 1];

        int r = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            res[i] *= r;
            r *= nums[i];
        }

        return res;
    }
};
