/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 207. Course Schedule
~ Link      : https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > adj(numCourses, vector<int> ());
        vector<int> indegree(numCourses, 0);
        vector<int> courseOrder;

        for (int i = 0; i < prerequisites.size(); ++i) {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[src].emplace_back(dest);
            ++indegree[dest];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {

            int currVertex = q.front();
            q.pop();
            courseOrder.emplace_back(currVertex);

            for (auto itr = adj[currVertex].begin(); itr != adj[currVertex].end(); ++itr)
                if (--indegree[*itr] == 0)
                    q.push(*itr);
        }

        if (courseOrder.size() == numCourses)
            return true;
        return false;
    }
};
