/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 503. Next Greater Element II
~ Link      : https://leetcode.com/problems/next-greater-element-ii/
*/

/* Efficient Approach */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; --i) {

            while (!s.empty() && nums[i % n] >= s.top())
                s.pop();

            if (!s.empty())
                res[i % n] = s.top();

            s.push(nums[i % n]);
        }

        return res;
    }
};

/* Brute-force Approach */
/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int j = i + 1, c = n;
            while (c --) {
                if (nums[j % n] > nums[i]) {
                    res[i] = nums[j % n];
                    break;
                }
                ++j;
            }
        }
        return res;
    }
};
*/
