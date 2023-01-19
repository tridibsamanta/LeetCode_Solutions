/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2171. Removing Minimum Number of Magic Beans
~ Link      : https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
*/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        long long totalBeans = accumulate(beans.begin(), beans.end(), 0LL);
        long long res = LLONG_MAX, prevRemoved = 0, i = 0;
        int totalBags = beans.size();

        while (i < beans.size()) {
            long long beanCount = beans[i], bagCount = 0;

            while (i < beans.size() && beans[i] == beanCount) {
                ++bagCount;
                ++i;
            }

            totalBeans -= (beanCount * bagCount);
            totalBags -= bagCount;

            long long currRes = prevRemoved + totalBeans - (beanCount * totalBags);

            prevRemoved += (beanCount * bagCount);

            res = min(res, currRes);
        }

        return res;
    }
};

// Time Complexity - O(n log n)
// Space Complexity - O(1)
