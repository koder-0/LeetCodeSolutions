/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        
        Node* left = treeToDoublyList(root->left);
        Node* right = treeToDoublyList(root->right);
        
        root->left = root;
        root->right = root;
        
        return connect(connect(left, root), right);
    }
    
    Node* connect(Node* root1, Node* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        
        Node* tail1 = root1->left;
        Node* tail2 = root2->left;
        
        tail1->right = root2;
        root2->left = tail1;
        tail2->right = root1;
        root1->left = tail2;
        
        return root1;
    }
};