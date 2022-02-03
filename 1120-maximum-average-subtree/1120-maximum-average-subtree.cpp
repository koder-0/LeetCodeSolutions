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
private:
    struct Subtree{
        int valueSum;
        int nodeCount;
        double bestAverage;
        
        Subtree(int value, int count, double average): valueSum(value), nodeCount(count), bestAverage(average){}
    };
    
    Subtree* BottomUpAverageSubtree(TreeNode* root){
        if(!root) return new Subtree(0,0,0.0);
        
        Subtree* left = BottomUpAverageSubtree(root->left);
        Subtree* right = BottomUpAverageSubtree(root->right);
        
        int value = left->valueSum+right->valueSum+root->val;
        int count = left->nodeCount+right->nodeCount+1;
        double average = max({((1.0*value)/count), left->bestAverage, right->bestAverage});
        
        return new Subtree(value, count, average);
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        return BottomUpAverageSubtree(root)->bestAverage;
    }
};