class Solution {
    
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 0;
        if(n == 1) return 1;
        vector<int> candy(n, 0);
        if(ratings[0] <= ratings[1]) {
            candy[0] = 1;
        }
        if(ratings[n-1] <= ratings[n-2]) {
            candy[n-1] = 1;
        }
        for(int i = 1; i < n-1; ++i) {
            if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) {
                candy[i] = 1;
            }
        }
        for(int i = 1; i < n; ++i) {
            if(candy[i-1] && ratings[i] > ratings[i-1]) {
                candy[i] = max(candy[i], candy[i-1]+1);
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(candy[i+1] && ratings[i] > ratings[i+1]) {
                candy[i] = max(candy[i], candy[i+1] +1 );
            }
        }
        for(int i = 0; i < n; ++i) {
            // cout<<candy[i]<<" ";
            res += candy[i];
        }
        return res;
    }
};