/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    multiset<char> operandSet;
    void filler(Node* root1){
        if(!root1) return ;
        filler(root1->left);
        if(isalpha(root1->val))
           operandSet.insert(root1->val);
        filler(root1->right);
    }
    
    bool Checker(Node* root){
        if(!root)return true;
        bool ret = true;
        ret &= Checker(root->left);
        ret &= Checker(root->right);
        if(isalpha(root->val)) {
            if(operandSet.find(root->val) != operandSet.end()){
                ret &= true;
                operandSet.erase(operandSet.find(root->val));
            }
            else ret &= false;
        }
        return ret;
    }
    bool checkEquivalence(Node* root1, Node* root2) {
        filler(root1);
        return Checker(root2);
        
    }
};