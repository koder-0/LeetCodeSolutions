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
    int d = 0;
    int height(Node* root){
        if(!root) return 0;
        
        int h_max = 0, h_second_max = 0;
        
        for(auto child: root->children){
            int h = height(child);
            if(h >= h_max)  h_second_max = h_max, h_max = h;
            else if(h > h_second_max) h_second_max = h;
        }
        
        d = max(d, h_max+h_second_max+1);
        return h_max+1;
    }
    int diameter(Node* root) {
        int h = height(root);
        return d-1;
    }
};