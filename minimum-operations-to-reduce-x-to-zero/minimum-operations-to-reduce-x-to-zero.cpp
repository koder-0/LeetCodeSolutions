class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int>pre(n+1, 0), preReverse(n+1,0);
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            preReverse[i] = preReverse[i+1] + nums[i];
        }
        reverse(begin(preReverse), end(preReverse));
        int res = INT_MAX;
        for(int i = 0; i <= n && pre[i] <= x; ++i){
            int val = x-pre[i];
            int idx = lower_bound(begin(preReverse), end(preReverse), val) - begin(preReverse);
            if(idx <= n-i && preReverse[idx] == val) res = min(res, i+idx);
        }
        
        
        return res > n ? -1 : res;
    }
};