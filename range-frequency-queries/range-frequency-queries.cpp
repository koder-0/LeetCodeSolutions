class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> idxMap;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            idxMap[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto it1 = lower_bound(begin(idxMap[value]), end(idxMap[value]), left)-begin(idxMap[value]);
        auto it2 = upper_bound(begin(idxMap[value]), end(idxMap[value]), right)-begin(idxMap[value]);
        return it2-it1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */