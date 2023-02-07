/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 974. Subarray Sums Divisible by K
~ Link      : https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

/*
Intuition:
nums = [2, 1, 10], k = 5

When i is 1 then prefSum = 3 and rem = 3 % 5 = 3
Again when i is 2 then prefSum = 13 and rem = 13 % 5 = 3

As the remainders are equal it must hold true that
the subarray sum from index 2 to 2 is a multiple of k,
otherwise we won't be getting the same remainder.

Thus we keep track of the freq of remainders from 0 to k - 1
and keep on adding them to the count as we encounter the
freq of remainder. And after that increment current remainder
count by 1.
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(k, 0);
        freq[0] = 1; // the first 0 is also divisible by 'k'

        int prefSum = 0, cnt = 0;

        for (int i = 0; i < n; ++i) {
            prefSum += nums[i];

            int rem = (prefSum % k + k) % k;

            cnt += freq[rem];
            ++freq[rem];
        }

        return cnt;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(k)
