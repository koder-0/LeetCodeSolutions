class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        auto low_it = lower_bound(begin(nums), end(nums), target);
        auto up_it = upper_bound(begin(nums), end(nums), target);
        vector<int>res;
        for(auto it = low_it; it != up_it; ++it){
            res.push_back(it-begin(nums));
        }
        return res;
    }
};