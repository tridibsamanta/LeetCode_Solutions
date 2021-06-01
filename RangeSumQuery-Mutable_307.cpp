/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 307. Range Sum Query - Mutable
~ Link      : https://leetcode.com/problems/range-sum-query-mutable/
*/

// fenwick tree approach

class NumArray {
public:
    int n;
    int arr[30003], bit[30003];

    NumArray(vector<int>& nums) {
        n = nums.size();

        for (int i = 0; i < n; ++i)
            arr[i+1] = nums[i];

        for (int i = 1; i <= n; ++i) {
            int j = i;
            for (; j <= n; j += (j & -j))
                bit[j] += arr[i];
        }
    }
    // O(n * log n)

    void update(int index, int val) {
        int i = index + 1;
        for (; i <= n; i += (i & -i))
            bit[i] += (val - arr[index + 1]);
        arr[index + 1] = val;
    }
    // O(log n)

    int sumRangeUtil(int i) {
        int ans = 0;
        for (; i > 0; i -= (i & -i))
            ans += bit[i];
        return ans;
    }
    // O(log n)

    int sumRange(int left, int right) {
        return sumRangeUtil(++right) - sumRangeUtil(left);
    }
};
