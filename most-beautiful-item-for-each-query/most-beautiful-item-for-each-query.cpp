class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        //[[1,2],[2,4],[3,2],[3,5],[5,6]]
        //well after short brainstorming(;) it seemed long to me tho)
        //I looked up in discussion and found out that I have to separate the prices and beauties
        // and then apply some modification, i.e., compute max beauty for each price less than equal to p
        //and then apply binary search
        //let's go
        
        int n = items.size();
        sort(begin(items), end(items));
        vector<int> prices, maxBeauty;
        int mx = 0;
        for(auto item: items){
            int price = item[0], beauty = item[1];
            prices.push_back(price);
            mx = max(mx, beauty);
            maxBeauty.push_back(mx);
        }
        
        vector<int>res;
        for(auto query: queries){
            auto it = upper_bound(begin(prices), end(prices), query)-begin(prices);
            it--;
            it >= 0 ? res.push_back(maxBeauty[it]) : res.push_back(0);
        }
        
        return res;
    }
};