/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 881. Boats to Save People
~ Link      : https://leetcode.com/problems/boats-to-save-people/
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        if (n < 2)
            return 1;

        sort(people.begin(), people.end());

        int l = 0, r = n - 1, cnt = 0;

        while (l < r) {
            if (people[l] + people[r] > limit)
                --r;
            else
                ++l, --r;

            ++cnt;
        }

        if (l == r)
            ++cnt;

        return cnt;
    }
};

// Time Complexity - O(n * log n)
// Auxiliary Space - O(1)
