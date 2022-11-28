/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1488. Avoid Flood in The City
~ Link      : https://leetcode.com/problems/avoid-flood-in-the-city/
*/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        unordered_map<int, int> lastFillIndex;
        set<int> dryIndex;

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                dryIndex.insert(i);
                ans[i] = 1;
            }
            else {
                // lake is already full
                if (lastFillIndex.count(rains[i])) {

                    // find index 'j' such that rains[j] == 0 and j > lastFillIndex[rains[i]]
                    auto posItr = dryIndex.lower_bound(lastFillIndex[rains[i]]);

                    // lake can be dried before current fill
                    if (posItr != dryIndex.end()) {
                        ans[*posItr] = rains[i];
                        dryIndex.erase(posItr);
                        lastFillIndex[rains[i]] = i;
                    }
                    // lake can't be dried before current fill
                    else {
                        ans.clear();
                        break;
                    }
                }
                // lake is not filled even once
                else {
                    lastFillIndex[rains[i]] = i;
                }
            }
        }

        return ans;
    }
};

// Time Complexity - O(n * log n)
// Auxiliary Space - O(n)
