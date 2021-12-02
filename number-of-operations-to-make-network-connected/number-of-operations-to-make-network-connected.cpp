class Solution {
public:
    vector<int> par;
    int find(int node){
        return par[node] == node ? node : find(par[node]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();
        if(n-1 > c) return -1;
        
        par.resize(n);
        for(int i = 0; i < n; ++i){
            par[i] = i;
        }
        
        for(auto connection: connections){
            int u = find(connection[0]);
            int v = find(connection[1]);
            if(u != v) par[v] = u;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(par[i] == i) ans++;
        
        return ans-1;
    }
    
};