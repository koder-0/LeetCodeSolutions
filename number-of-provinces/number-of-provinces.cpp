class Solution {
public:
    
    void Util(vector<vector<int>>& isConnected, int node, bool vis[]){
        for(int child = 0; child < isConnected[node].size(); ++child){
            if(!vis[child] && isConnected[node][child]){
                vis[child] = true;
                Util(isConnected, child, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int numProvinces = 0;
        bool vis[201] = {false};

        int n = isConnected.size();
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                numProvinces++;
                vis[i] = true;
                Util(isConnected, i, vis);
            }
        }
        
        return numProvinces;
    }
};