/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 1233. Remove Sub-Folders from the Filesystem
~ Link      : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        vector<string> res;

        sort(folder.begin(), folder.end());
        res.emplace_back(folder[0]);

        for (int i = 1; i < folder.size(); ++i) {
            string curr = res[res.size() - 1] + '/';
            string pre = folder[i].substr(0, curr.size());

            if (pre != curr)
                res.emplace_back(folder[i]);
        }

        return res;
    }
};
