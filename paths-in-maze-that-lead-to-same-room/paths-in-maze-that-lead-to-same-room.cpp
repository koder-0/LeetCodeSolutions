class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<vector<int>>adj(n+1);
        vector<vector<bool>> isConnected(n+5, vector<bool>(n+5, false));
        
        for(auto corridor: corridors){
            int u = corridor[0], v = corridor[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            isConnected[u][v] = 1;
            isConnected[v][u] = 1;
        }
        
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j: adj[i]){
                for(int k: adj[i]){
                    if(isConnected[j][k]) ans++;
                }
            }
        }
        
        return ans/6;
    }
};