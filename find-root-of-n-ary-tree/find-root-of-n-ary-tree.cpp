/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> nodes;
        for(auto node: tree)
            nodes.insert(node->children.begin(), node->children.end());
        for(auto node: tree)
            if(nodes.count(node) == 0) return node;
        return NULL;
    }
};