/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
~ Link      : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/

struct DSU {
	int n, comp;
	vector<int> parent, compSz;

	DSU(int N) {
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

	    for (auto vec : edges) {
		    dsu.Merge(vec[0] + 1, vec[1] + 1);
	    }

	    unordered_map<int, int> componentSize;

	    for (int i = 1; i <= n; ++i) {
            int parent = dsu.Find(i);
		    componentSize[parent] = dsu.compSz[parent];
	    }

	    long long unreachablePairCount = 0, remNodes = n;

	    for (auto p : componentSize) {
		    unreachablePairCount += (p.second * 1ll * (remNodes - p.second));
            remNodes -= p.second;
	    }

	    return unreachablePairCount;
    }
};

// Time Complexity - O(n + e)
// Space Complexity - O(n)
