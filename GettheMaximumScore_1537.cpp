/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1537. Get the Maximum Score
~ Link      : https://leetcode.com/problems/get-the-maximum-score/
*/

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long int score = 0, sum1 = 0, sum2 = 0;
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;

        while (i < n && j < m) {
            // move in nums1 by a node
            if (nums1[i] < nums2[j])
                sum1 += nums1[i++];
            // move in nums2 by a node
            else if (nums2[j] < nums1[i])
                sum2 += nums2[j++];
            // node having same value is encountered
            else if (nums1[i] == nums2[j]) {
                // take max of the two paths
                score += max(sum1, sum2) + nums1[i];

                // reset both path sum
                sum1 = sum2 = 0;

                // move forward by a node in nums1 & nums2
                ++i, ++j;
            }
        }

        // remaining nodes in nums1
        while (i < n)
            sum1 += nums1[i++];

        // remaining nodes in nums2
        while (j < m)
            sum2 += nums2[j++];

        // take max of the two paths
        score += max(sum1, sum2);

        return (score % 1000000007);
    }
};

// Time Complexity - O(n + m)
// Space Complexity - O(1)
