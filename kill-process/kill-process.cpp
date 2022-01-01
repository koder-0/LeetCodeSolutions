class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> res;
    
    void dfs(int node){
        for(auto child: mp[node]){
            dfs(child);
        }
        res.push_back(node);
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int size = pid.size();
        for(int i = 0; i < size; ++i){
            mp[ppid[i]].push_back(pid[i]);
        }
        
        dfs(kill);
        return res;
    }
};