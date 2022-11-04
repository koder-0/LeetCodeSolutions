class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(auto num: nums) cout<<num<<" ";
        if(n < 3) return {};
        if(nums[0] > 0) return {};
        vector<vector<int>> res;
        for(int i = 0; i < n && nums[i] <= 0; ++i) {
            if(i && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[k-1] == nums[k]) k--;
                    while(j < k && nums[j+1] == nums[j]) j++;
                    k--; j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    while(j < k && nums[k-1] == nums[k]) k--;
                    k--;
                }
                else {
                    while(j < k && nums[j+1] == nums[j]) j++;
                    j++;
                }
            }
        }
        return res;
    }
};