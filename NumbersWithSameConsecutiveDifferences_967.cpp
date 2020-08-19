/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 967. Numbers With Same Consecutive Differences
~ Link      : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {

        vector<int> res;
        queue<int> q;

        for(int i = 1; i <= 9; ++i)
            q.push(i);

        for (int i = 1; i < N; ++i) {

            int q_size = q.size();

            while (q_size--) {

                int curr = q.front();
                q.pop();

                int ud = curr % 10;

                if (ud + K < 10)
                    q.push(curr * 10 + ud + K);
                if (K > 0 && ud - K >= 0)
                    q.push(curr * 10 + ud - K);
            }
        }

        if (N == 1)
            res.emplace_back(0);

        while (!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }

        return res;
    }
};
