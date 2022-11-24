/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 133. Clone Graph
~ Link      : https://leetcode.com/problems/clone-graph/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void cloneGraphUtil(Node *node, unordered_map<Node*, Node*> &ump) {

        Node *currCopy = new Node(node -> val);
        ump[node] = currCopy;

        for (Node *adjNode : node -> neighbors) {
            if (ump.count(adjNode) == 0)
                cloneGraphUtil(adjNode, ump);

            (currCopy -> neighbors).emplace_back(ump[adjNode]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;

        unordered_map<Node*, Node*> ump;

        cloneGraphUtil(node, ump);

        return ump[node];
    }
};

// Time Complexity - O(vertices + edges)
// Auxiliary Space - O(vertices)
