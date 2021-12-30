/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
   
    Node* flipBinaryTree(Node* root, Node * leaf) {
        if(!root) return NULL;
        
        Node* curr = leaf, *par = leaf->parent, *newPar = NULL;
        while(curr){
            par = curr->parent;
            if(par && curr->left){
                curr->right = curr->left;
                curr->left = NULL;
            }
            if(!curr->left)curr->left = par;
            if(par){
                if(par->left == curr) par->left = NULL;
                else par->right = NULL;
            }
            curr->parent = newPar;
            newPar = curr;
            curr = par;
        }
        
        curr = leaf;
        return leaf;
    }
};