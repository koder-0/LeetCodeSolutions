/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int p, int q){
        if(!root) return NULL;
        if(root->val == p || root->val == q) return root;
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if(!left && !right) return NULL;
        else if(left && !right) return left;
        else if(!left && right) return right;
        else return root;
    }
    
    int findDistToNode(TreeNode* root, int val){
        if(!root) return -1;
        if(root->val == val) return 0;
        int left = findDistToNode(root->left,val);
        int right = findDistToNode(root->right, val);
        if(left >= 0) return left+1;
        else if(right >= 0) return right+1;
        else return -1;
        
    }
    
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* lcaNode = findLCA(root, p, q);
        cout<<lcaNode->val<<endl;
        int distP = findDistToNode(lcaNode, p);
        int distQ = findDistToNode(lcaNode, q);
        return distP+distQ;
    }
};