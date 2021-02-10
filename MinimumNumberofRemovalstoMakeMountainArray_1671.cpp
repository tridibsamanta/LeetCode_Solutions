/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1671. Minimum Number of Removals to Make Mountain Array
~ Link      : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*/

// The result is = total number of elements in the given array - the longest bitonic subsequence length

/* Approach 1 (Using Binary Search + DP) */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp1(n, 1);
        vector<int> seq;

        seq.emplace_back(nums[0]);

        for (int i = 1; i < n; ++i) {

            auto itr = lower_bound(seq.begin(), seq.end(), nums[i]);

            if (itr == seq.end())
                seq.emplace_back(nums[i]);
            else
                *itr = nums[i];

            dp1[i] = seq.size();
        }

        seq.clear();

        vector<int> dp2(n, 1);

        seq.emplace_back(nums[n - 1]);

        for (int i = n - 2; i >= 0; --i) {

            auto itr = lower_bound(seq.begin(), seq.end(), nums[i]);

            if (itr == seq.end())
                seq.emplace_back(nums[i]);
            else
                *itr = nums[i];

            dp2[i] = seq.size();
        }

        /*
            We don't want to form strictly increasing or strictly decreasing sequences.
            Hence we need to make sure that LIS length at dp1[i] and dp2[i] both are greater than 1.
            Its obvious that we don't need to consider the 0'th and (n-1)'th index of the dp arrays as they contain 1.
        */

        int maxLen = 0;

        for (int i = 1; i < n - 1; ++i) {

            if (dp1[i] > 1 && dp2[i] > 1)
                maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
        }

        return n - maxLen;
    }
};

// T.C. - O(nlogn)
// S.C. - O(n)


/* Approach 2 (Using DP) */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

	    vector<int> dp1(n, 1);

	    for (int i = 1; i < n; ++i) {

	        for (int j = 0; j < i; ++j) {

	            if (nums[i] > nums[j])
	                dp1[i] = max(dp1[i], dp1[j] + 1);
	        }
	    }

        vector<int> dp2(n, 1);

	    for (int i = n - 2; i >= 0; --i) {

	        for (int j = n - 1; j > i; --j) {

	            if (nums[i] > nums[j])
	                dp2[i] = max(dp2[i], dp2[j] + 1);
	        }
	    }

        int maxLen = 0;

	    for (int i = 1; i < n - 1; ++i) {

            if (dp1[i] > 1 && dp2[i] > 1)
	            maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
        }

	    return n - maxLen;
    }
};

// T.C. - O(n^2)
// S.C. - O(n)
