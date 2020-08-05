/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 211. Add and Search Word - Data structure design
~ Link      : https://leetcode.com/problems/add-and-search-word-data-structure-design/
*/

class WordDictionary {
public:
    struct Node {
        bool end;
        Node *nodes[26];
        Node() {
            end=false;
            memset(nodes, 0, 26*sizeof(Node*));
        }
    } *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node(), root -> end = true;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur=root;
        for (char c : word) {
            Node*& n = cur->nodes[c-'a'];
            cur = n ? n : (n=new Node());
        }
        cur->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, 0, root);
    }

    bool find(string& word, int pos, Node *from) {
        if (pos==word.length())
            return from->end;

        if (word[pos]=='.')
            for (auto& n : from->nodes)
                if (n && find(word, pos+1, n))
                    return true;
                else;
        else
            return from->nodes[word[pos]-'a'] ? find(word, pos+1, from->nodes[word[pos]-'a']) : false;

        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
