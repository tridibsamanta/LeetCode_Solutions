/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 146. LRU Cache
~ Link      : https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    // Doubly Linked List Node
    class Node {
    public:
        int key, val;
        Node *next, *prev;

        Node(int init_key, int init_val) {
            key = init_key;
            val = init_val;

            next = prev = NULL;
        }
    };

    // node after the head node is the recently used
    Node *head = new Node(-1, -1);

    // node before the tail node is the least recently used
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node*> hm;
    int cacheCapacity;

    LRUCache(int capacity) {
        cacheCapacity = capacity;

        head -> next = tail;
        tail -> prev = head;
    }

    void insertNode(Node *targetNode) {
        Node *temp = head -> next;
        head -> next = targetNode;
        targetNode -> prev = head;
        targetNode -> next = temp;
        temp -> prev = targetNode;
    }

    void deleteNode(Node *targetNode) {
        Node *prevTarget = targetNode -> prev;
        Node *nextTarget = targetNode -> next;
        prevTarget -> next = nextTarget;
        nextTarget -> prev = prevTarget;
    }

    int get(int target_key) {

        if (hm.find(target_key) != hm.end()) {

            Node *targetNode = hm[target_key];
            int target_val = targetNode -> val;

            deleteNode(targetNode);
            insertNode(new Node(target_key, target_val));

            hm[target_key] = head -> next;

            return target_val;
        }

        return -1;
    }

    void put(int target_key, int target_value) {

        if (hm.find(target_key) != hm.end()) {

            Node *existingNode = hm[target_key];
            deleteNode(existingNode);
            hm.erase(target_key);
        }

        if (hm.size() == cacheCapacity) {

            hm.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        insertNode(new Node(target_key, target_value));
        hm[target_key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
