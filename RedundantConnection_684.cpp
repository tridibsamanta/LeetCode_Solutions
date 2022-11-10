/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 684. Redundant Connection
~ Link      : https://leetcode.com/problems/redundant-connection/
*/

/* Approach 1 (Using DFS) */
/*
class Solution {
public:
    void isGraphConnectedUtil(int u, vector<bool> &visited, vector<vector<int> > &adj) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v])
                isGraphConnectedUtil(v, visited, adj);
        }
    }

    bool isGraphConnected(vector<vector<int> > &adj) {
        int v = adj.size();

        vector<bool> visited(v, false);

        isGraphConnectedUtil(0, visited, adj);

        for (int i = 0; i < v; ++i) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> redundantConnection;
        vector<vector<int> > adj(n);

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0] - 1, v = edges[i][1] - 1;

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        // Remove each edge from back and check for connectivity
        for (int i = n - 1; i >= 0; --i) {
            int u = edges[i][0] - 1, v = edges[i][1] - 1;

            adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));

            if (isGraphConnected(adj)) {
                redundantConnection.emplace_back(edges[i][0]);
                redundantConnection.emplace_back(edges[i][1]);

                break;
            }

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        return redundantConnection;
    }
};
*/
// Time Complexity - O(n ^ 2)
// Space Complexity - O(n)

/* Approach 2 (Using DSU) */

struct DSU {
	int n, comp;
	vector<int> parent, compSz;
	void init(int N) {
		n = N;
		parent.resize(n + 1, -1);
		compSz.resize(n + 1, 1);
		comp = n;
	}
	int Find(int x) {
		if (parent[x] < 0)
			return x;
		return parent[x] = Find(parent[x]);
	}
	bool Merge(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x == y)
			return false;
		if (compSz[x] > compSz[y])
			swap(x, y);
		parent[x] = y;
		compSz[y] += compSz[x];
		--comp;
		return true;
	}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> redundantConnection;

        DSU d1;
        d1.init(n);

        for (auto curr : edges) {
            int rep_u = d1.Find(curr[0]);
            int rep_v = d1.Find(curr[1]);

            if (rep_u == rep_v) {
                redundantConnection.emplace_back(curr[0]);
                redundantConnection.emplace_back(curr[1]);

                break;
            }

            d1.Merge(curr[0], curr[1]);
        }

        return redundantConnection;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
