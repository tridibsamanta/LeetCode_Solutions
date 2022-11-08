/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 721. Accounts Merge
~ Link      : https://leetcode.com/problems/accounts-merge/
*/

class Solution {
private:
    unordered_map<string, vector<string> > adj;
    unordered_map<string, bool> visited;
    vector<string> merged;

    void dfs(string currEmail) {
        visited[currEmail] = true;
        merged.emplace_back(currEmail);

        for (auto adjEmail : adj[currEmail]) {
            if (!visited[adjEmail])
                dfs(adjEmail);
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // creating graph where emails are nodes
        for (auto curr : accounts) {
            visited[curr[1]] = false;

            for (int i = 1; i < curr.size() - 1; ++i) {
                adj[curr[i]].emplace_back(curr[i + 1]);
                adj[curr[i + 1]].emplace_back(curr[i]);

                visited[curr[i + 1]] = false;
            }
        }

        vector<vector<string> > res;

        // initiate dfs from every person's first email
        // if current node(email) is not visited and form the res
        for (auto curr : accounts) {

            if (visited[curr[1]])
                continue;

            merged.clear();
            merged.emplace_back(curr[0]); // put the person name

            // dfs on current component
            dfs(curr[1]);

            // sort emails
            sort(merged.begin() + 1, merged.end());

            res.emplace_back(merged);
        }

        return res;
    }
};


// Time Complexity - O(nm log nm)
// Space Complexity - O(nm)
// where n = accounts.size() and m = accounts[i].size()
