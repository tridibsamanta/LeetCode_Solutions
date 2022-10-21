/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 378. Kth Smallest Element in a Sorted Matrix
~ Link      : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

// Approach 1 (Using max-heap)
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pq.push(matrix[i][j]);

                if (pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};
*/
// Time Complexity - O(n * n * log k)
// Auxiliary Space - O(k)

// Approach 2 (Using min-heap)
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();

        // {element, row_index, column_index}
        priority_queue<vector<int>, vector<vector<int> >, greater<> > pq;

        for (int i = 0; i < min(k, row); ++i) {
            pq.push({matrix[i][0], i, 0});
        }

        for (int i = 1; i < k; ++i) {
            vector<int> currMin = pq.top();
            pq.pop();

            int currRowIndex = currMin[1], nextColIndex = currMin[2] + 1;

            if (nextColIndex < col)
                pq.push({matrix[currRowIndex][nextColIndex], currRowIndex, nextColIndex});
        }

        return pq.top()[0];
    }
};
*/
// Time Complexity - O(k * log k)
// Auxiliary Space - O(k)

// Approach 3 (Using Binary Search)

class Solution {
public:
    int countLessOrEqual(int value, vector<vector<int> > &matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int currRow = 0, currCol = col - 1, count = 0;

        while (currRow < row && currCol >= 0) {
            if (matrix[currRow][currCol] <= value) {
                count += currCol + 1;
                ++currRow;
            }
            else {
                --currCol;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int lo = matrix[0][0], hi = matrix[row - 1][col - 1], ans;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (countLessOrEqual(mid, matrix, k) >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};

// Time Complexity - O((r + c) * log x), where r = matrix.size(),
// c = matrix[0].size() & x = max(matrix[i][j]) - min(matrix[i][j])
// Auxiliary Space - O(1)
