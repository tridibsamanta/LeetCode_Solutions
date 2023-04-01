/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1466. Reorder Routes to Make All Paths Lead to the City Zero
~ Link      : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool> > > adj(n);

        for (auto vec : connections) {
            adj[vec[0]].push_back({vec[1], false});
            adj[vec[1]].push_back({vec[0], true});
        }

        queue<pair<int, int> > todo; // {vertex, parent}
        todo.push({0, -1});

        int reorderCount = 0;

        while (!todo.empty()) {
            int curr = todo.front().first;
            int parent = todo.front().second;
            todo.pop();

            for (auto p : adj[curr]) {
                int v = p.first;
                bool edgeExists = p.second;

                if (v != parent) {
                    todo.push({v, curr});
                    reorderCount += !edgeExists;
                }
            }
        }

        return reorderCount;
    }
};

// Time Complexity - O(v + e)
// Space Complexity - O(v + e)
