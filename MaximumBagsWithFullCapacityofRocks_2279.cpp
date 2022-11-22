/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2279. Maximum Bags With Full Capacity of Rocks
~ Link      : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size(), fullBagsCount = 0;

        vector<int> deficit;

        for (int i = 0; i < n; ++i) {
            if (rocks[i] == capacity[i])
                ++fullBagsCount;
            else
                deficit.emplace_back(capacity[i] - rocks[i]);
        }

        if (deficit.empty())
            return n;

        sort(deficit.begin(), deficit.end());

        for (int i = 0; i < deficit.size(); ++i) {
            if (deficit[i] > additionalRocks)
                break;

            ++fullBagsCount;
            additionalRocks -= deficit[i];
        }

        return fullBagsCount;
    }
};

// Time Complexity - O(n log n)
// Auxiliary Space - O(n)
