/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isGridUnival(vector<vector<int>>& grid, int x, int y, int len){
        bool res = grid[x][y];
        for(int i = x; i < x+len; ++i){
            for(int j = y; j < y+len; ++j){
                if(grid[i][j] != res) return false;
            }
        }
        
        return true;
    }
    
    Node* Util(vector<vector<int>>& grid, int st_x, int st_y, int len){
        Node* root = new Node();
        if(isGridUnival(grid, st_x, st_y, len)){
            root->isLeaf = true;
            root->val = grid[st_x][st_y];
            return root;
        }
        root->isLeaf = false;
        root->val = 1;
        root->topLeft = Util(grid, st_x, st_y, len/2);
        root->topRight = Util(grid, st_x, st_y+len/2, len/2);
        root->bottomLeft = Util(grid, st_x+len/2, st_y, len/2);
        root->bottomRight = Util(grid, st_x+len/2, st_y+len/2, len/2);
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        Node* root = Util(grid, 0, 0, n);
        return root;
    }
};