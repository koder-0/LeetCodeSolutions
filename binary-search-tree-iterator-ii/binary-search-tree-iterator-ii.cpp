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
class BSTIterator {
private:
    stack<TreeNode*> inorderStack;
    vector<TreeNode*> inorderArr;
    int ptr;
    TreeNode* last;
public:
    BSTIterator(TreeNode* root) {
        last = root;
        ptr = -1;
    }
    
    bool hasNext() {
        if(last || inorderStack.empty() == false || ptr + 1 < inorderArr.size()) return true;
        return false;
    }
    
    int next() {
        ptr++;
        if(ptr >= inorderArr.size()){
            while(last){
                inorderStack.push(last);
                last = last->left;
            }
            last = inorderStack.top();
            inorderStack.pop();
            inorderArr.push_back(last);
            last = last->right;
        }
        
        return inorderArr[ptr]->val;
    }
    
    bool hasPrev() {
        return ptr > 0;
    }
    
    int prev() {
        ptr--;
        return inorderArr[ptr]->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */