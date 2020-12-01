/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1282. Group the People Given the Group Size They Belong To
~ Link      : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        int n = groupSizes.size();

        vector<vector<int> > allocate(n + 1);

        for (int i = 0; i < n; ++i)
            allocate[groupSizes[i]].emplace_back(i);

        vector<vector<int> > groups;

        for (int i = 1; i <= n; ++i) {

            int total = allocate[i].size() / i, idx = 0;

            while (total--) {

                vector<int> curr_group;

                for (int k = 0; k < i; ++k)
                    curr_group.emplace_back(allocate[i][idx++]);

                groups.emplace_back(curr_group);
            }

        }

        return groups;
    }
};
