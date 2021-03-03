/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 152. Maximum Product Subarray
~ Link      : https://leetcode.com/problems/maximum-product-subarray/
*/

// Approach 1 (Bottom-up)
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, 0), dp2(n, 0);

        dp1[0] = nums[0];
        dp2[n-1] = nums[n-1];

        int maxProd = max(dp1[0], dp2[n-1]);

        for (int i = 1; i < n; ++i) {

            if (dp1[i-1] == 0)
                dp1[i] = nums[i];
            else
                dp1[i] = dp1[i-1] * nums[i];

            if (dp2[n-i] == 0)
                dp2[n-i-1] = nums[n-i-1];
            else
                dp2[n-i-1] = dp2[n-i] * nums[n-i-1];

            maxProd = max(maxProd, max(dp1[i], dp2[n-i-1]));
        }

        return maxProd;
    }
};

// T.C. - O(n)
// S.C. - O(n)
*/

// Approach 2 (Bottom-up)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int prefProd = nums[0];
        int suffProd = nums[n-1];

        int maxProd = max(prefProd, suffProd);

        for (int i = 1; i < n; ++i) {

            if (prefProd == 0)
                prefProd = nums[i];
            else
                prefProd *= nums[i];

            if (suffProd == 0)
                suffProd = nums[n-i-1];
            else
                suffProd *= nums[n-i-1];

            maxProd = max(maxProd, max(prefProd, suffProd));
        }

        return maxProd;
    }
};

// T.C. - O(n)
// S.C. - O(1)
