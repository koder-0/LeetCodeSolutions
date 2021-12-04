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
    int postOrder(TreeNode* root, int& cnt){
        if(!root) return 0;
        int left = postOrder(root->left, cnt);
        int right = postOrder(root->right, cnt);
        int val = (root->val+left+right-1);
        cnt += abs(left)+abs(right);
        return val;
        
    }
    int distributeCoins(TreeNode* root) {
        int cnt = 0;
        int x = postOrder(root, cnt);
        return cnt;
    }
};