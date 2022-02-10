class ThroneInheritance {
public:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> deathStatus;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        graph[parentName].push_back(childName);
    }
    
    void death(string name) {
        deathStatus[name] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(res, king);
        return res;
    }
    
    void dfs(vector<string> &res, string node){
        if(deathStatus[node] == false) res.push_back(node);
        for(auto child: graph[node]){
            dfs(res, child);
        }
        return;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */