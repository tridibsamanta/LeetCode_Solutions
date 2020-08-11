/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 274. H-Index
~ Link      : https://leetcode.com/problems/h-index/
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n)
                ++freq[n];
            else
                ++freq[citations[i]];
        }

        int papers = 0, h;
        for (h = n; h >= 0; --h) {
            papers += freq[h];
            if (papers >= h)
                break;
        }

        return h;
    }
};
