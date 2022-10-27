/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 373. Find K Pairs with Smallest Sums
~ Link      : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

class Solution {
public:
    struct compare {
        bool operator()(const vector<int> &v1, const vector<int> &v2) {
            return (v1[0] + v1[1]) > (v2[0] + v2[1]);
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > res;

        if (nums1.size() == 0 || nums2.size() == 0 || k == 0)
            return res;

        // min-heap --> {nums1_element, nums2_element, nums2_index}
        priority_queue<vector<int>, vector<vector<int> >, compare> pq;

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            pq.push({nums1[i], nums2[0], 0});
        }

        while (!pq.empty() && k--) {
            vector<int> currPair = pq.top();
            pq.pop();

            res.push_back({currPair[0], currPair[1]});

            int nextNums2Index = currPair[2] + 1;

            if (nextNums2Index < nums2.size()) {
                pq.push({currPair[0], nums2[nextNums2Index], nextNums2Index});
            }
        }

        return res;
    }
};

// Time Complexity - O(k * log k)
// Auxiliary Space - O(k)
