/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 827. Making A Large Island
~ Link      : https://leetcode.com/problems/making-a-large-island/
*/

/* Approach 1: (Brute-force using DFS) -> TLE */
/*
class Solution {
public:
    int maxIslandSize;
    vector<vector<bool> > visited;

    void largestIslandSizeUtil(int r, int c, vector<vector<int> > &grid,
                           int n, int &currIslandSize) {
        visited[r][c] = true;
        ++currIslandSize;

        static int row4D[] = { -1, 0, 1, 0};
        static int col4D[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; ++k) {
            int adj_r = r + row4D[k];
            int adj_c = c + col4D[k];

            if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < n)
               && grid[adj_r][adj_c] == 1 && !visited[adj_r][adj_c])
                largestIslandSizeUtil(adj_r, adj_c, grid, n, currIslandSize);
        }
    }

    void largestIslandSize(vector<vector<int> > &grid, int n) {
        visited.clear();
        visited.resize(n, vector<bool> (n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    int currIslandSize = 0;

                    largestIslandSizeUtil(i, j, grid, n, currIslandSize);

                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        maxIslandSize = 0;

        largestIslandSize(grid, n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;

                    largestIslandSize(grid, n);

                    grid[i][j] = 0;
                }
            }
        }

        return maxIslandSize;
    }
};
*/
// Time Complexity - O(n^4)
// Auxiliary Space - O(n^2)

/* Approach 2: (Using Disjoint Set Union) */

class Solution {
public:
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

    DSU d1;

    vector<int> row4D = { -1, 0, 1, 0};
    vector<int> col4D = {0, 1, 0, -1};

    void largestIslandSize(vector<vector<int> > &grid, int n) {

		d1.init(n * n);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0)
					continue;

				for (int k = 0; k < 4; ++k) {
					int adj_r = i + row4D[k];
					int adj_c = j + col4D[k];

					if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < n)
					        && grid[adj_r][adj_c] == 1)
						d1.Merge((i * n) + j + 1, (adj_r * n) + adj_c + 1);
				}
			}
		}
	}

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxCompSz = 0;

        largestIslandSize(grid, n);

        for (auto currCompSz : d1.compSz) {
		    maxCompSz = max(maxCompSz, currCompSz);
	    }

		for (int r = 0; r < n; ++r) {
		    for (int c = 0; c < n; ++c) {

                if (grid[r][c] == 0) {

                    set<int> rep;

				    for (int k = 0; k < 4; ++k) {
					    int adj_r = r + row4D[k];
					    int adj_c = c + col4D[k];

					    if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < n)
                            && grid[adj_r][adj_c] == 1) {

						    int currRep = d1.Find((adj_r * n) + adj_c + 1);
						    rep.insert(currRep);
                        }
				    }

                    int currCompSz = 1;

				    for (auto i : rep) {
					    currCompSz += d1.compSz[i];
				    }

		            maxCompSz = max(maxCompSz, currCompSz);
			    }
		    }
	    }

		return maxCompSz;
    }
};

// Time Complexity - O(n * n * log n)
// Auxiliary Space - O(n * n)

/* Approach 3: (Using DFS & unordered-map) */
/*
class Solution {
public:
    int islandCount = 0;
    unordered_map<int, int> islandId, islandSize;
    vector<vector<bool> > visited;

    vector<int> row4D = { -1, 0, 1, 0};
    vector<int> col4D = {0, 1, 0, -1};

    void identifyAllIslandsUtil(int r, int c, vector<vector<int> > &grid,
                           int n, int &currIslandSize) {
        visited[r][c] = true;
        islandId[(r * n) + c + 1] = islandCount;
        ++currIslandSize;

        for (int k = 0; k < 4; ++k) {
            int adj_r = r + row4D[k];
            int adj_c = c + col4D[k];

            if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < n)
               && grid[adj_r][adj_c] == 1 && !visited[adj_r][adj_c])
                identifyAllIslandsUtil(adj_r, adj_c, grid, n, currIslandSize);
        }
    }

    void identifyAllIslands(vector<vector<int> > &grid, int n, int &maxIslandSize) {
        visited.resize(n, vector<bool> (n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++islandCount;
                    int currIslandSize = 0;

                    identifyAllIslandsUtil(i, j, grid, n, currIslandSize);

                    islandSize[islandCount] = currIslandSize;
                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxIslandSize = 0;

        identifyAllIslands(grid, n, maxIslandSize);

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {

                if (grid[r][c] == 0) {
                    set<int> rep;

				    for (int k = 0; k < 4; ++k) {
					    int adj_r = r + row4D[k];
					    int adj_c = c + col4D[k];

					    if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < n)
                            && grid[adj_r][adj_c] == 1) {

						    rep.insert(islandId[(adj_r * n) + adj_c + 1]);
                        }
				    }

                    int currCompSz = 1;

				    for (auto i : rep) {
					    currCompSz += islandSize[i];
				    }

		            maxIslandSize = max(maxIslandSize, currCompSz);
			    }
            }
        }

        return maxIslandSize;
    }
};
*/
// Time Complexity - O(n * n)
// Auxiliary Space - O(n * n)
