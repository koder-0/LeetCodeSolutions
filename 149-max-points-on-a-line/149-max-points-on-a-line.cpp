class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        map<pair<int, int>, int> cntMap;
        int duplicates = 1;
        int n = points.size();
        for(int i = 0; i < n; ++i) {
            cntMap.clear();
            duplicates = 1;
            for(int j = i+1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx == 0 && dy == 0) {
                    duplicates++;
                    res = max(res, duplicates);
                    continue;
                }
                int gcd = __gcd(dx, dy);
                if(dx) dx = dx/gcd;
                if(dy) dy = dy/gcd;
                auto iter = cntMap.find({dx,dy});
                if(iter != cntMap.end()) {
                    (iter->second)++;
                    res = max(res, duplicates+(iter->second));
                }
                else {
                    cntMap[{dx,dy}] = 1;
                    res = max(res, duplicates+1);
                }
            }
        }
        
        return res;
    }
};