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
    unordered_set<TreeNode*> s;
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        if(root->right != NULL && s.count(root->right))return NULL;
        
        s.insert(root);
        
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
        
        return root;
    }
};