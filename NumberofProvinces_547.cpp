/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 547. Number of Provinces
~ Link      : https://leetcode.com/problems/number-of-provinces/
*/

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
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();

        DSU d1;
        d1.init(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    d1.Merge(i + 1, j + 1);
                }
            }
        }

        return d1.comp;
    }
};

// Time Complexity - O(n * n * log n)
// Space Complexity - O(n)
