/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 295. Find Median from Data Stream
~ Link      : https://leetcode.com/problems/find-median-from-data-stream/
*/

// Approach 1 (Using sorting)
/*
class MedianFinder {
private:
    vector<int> nums;
public:
    void addNum(int num) {
        nums.emplace_back(num);
    }

    double findMedian() {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n & 1)
            return nums[n / 2];
        else
            return ((double)nums[(n / 2) - 1] + nums[n / 2]) / 2;
    }
};
*/
// T.C. - O(nlogn)
// S.C. - O(n)

// Approach 2 (Using insertion sort)
/*
class MedianFinder {
private:
    vector<int> nums;
public:
    void addNum(int num) {
        if (nums.size() == 0)
            nums.emplace_back(num);
        else
            nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
    }

    double findMedian() {
        int n = nums.size();

        if (n & 1)
            return nums[n / 2];
        else
            return ((double)nums[(n / 2) - 1] + nums[n / 2]) / 2;
    }
};
*/
// T.C. - O(logn) + O(n) = O(n)
// S.C. - O(n)

// Approach 3 (Using Min-Heap & Max-Heap)

class MedianFinder {
private:
    priority_queue<int> pqmx;
    priority_queue<int, vector<int>, greater<int> > pqmn;

public:
    void addNum(int num) {
        pqmx.push(num);

        pqmn.push(pqmx.top());
        pqmx.pop();

        if (pqmx.size() < pqmn.size()) {
            pqmx.push(pqmn.top());
            pqmn.pop();
        }
    }

    double findMedian() {
        if (pqmx.size() > pqmn.size())
            return pqmx.top();
        else
            return ((double) pqmx.top() + pqmn.top())/ 2;
    }
};

// T.C. - O(logn)
// S.C. - O(n)
