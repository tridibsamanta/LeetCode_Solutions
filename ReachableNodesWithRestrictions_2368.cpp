/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2368. Reachable Nodes With Restrictions
~ Link      : https://leetcode.com/problems/reachable-nodes-with-restrictions/
*/

class Solution {
public:
    void dfs(int u, vector<vector<int> > &adj, vector<int> &visited, int &visitedCount) {
        ++visitedCount;
        visited[u] = 1;

        for (auto v : adj[u]) {
            if (!visited[v])
                dfs(v, adj, visited, visitedCount);
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int> > adj(n);

        for (auto vec : edges) {
            adj[vec[0]].emplace_back(vec[1]);
            adj[vec[1]].emplace_back(vec[0]);
        }

        vector<int> visited(n, 0);
        int visitedCount = 0;

        for (auto u : restricted) {
            visited[u] = 2;
        }

        dfs(0, adj, visited, visitedCount);

        return visitedCount;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
