/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1588. Sum of All Odd Length Subarrays
~ Link      : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size(), sum = arr[0];

        for (int i = 1; i < n; ++i)
            arr[i] = sum += arr[i];


        for (int len = 3; len <= n; len += 2) {

            sum += arr[len - 1];

            for (int i = len; i < n; ++i)
                sum += (arr[i] - arr[i - len]);
        }

        return sum;
    }
};
