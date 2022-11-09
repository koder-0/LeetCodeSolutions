class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, minDiff = INT_MAX;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int x = nums[i];
            int j = i+1, k = n-1;
            while(j < k) {
                int y = nums[j], z = nums[k];
                int sum = x+y+z;
                int diff = target-sum;
                if(diff == 0){
                    return sum;
                }
                else if(diff < 0) {
                    if(abs(diff) < minDiff) {
                        minDiff = abs(diff);
                        res = sum;
                    }
                    k--;
                }
                else{
                    if(abs(diff) < minDiff) {
                        minDiff = abs(diff);
                        res = sum;
                    }
                    j++;
                }
            }
        }
        return res;
    }
};