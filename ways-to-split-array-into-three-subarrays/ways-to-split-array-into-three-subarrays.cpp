class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        //prefix sum karenge
        //fir for each number kuch kuch to karne se ho jana chahiye
        //lower_bound nikalenge each number k liye
        //lower bound se lekar last tak sab candidate hai second segment k end ke
        //kuch exclude honge, uska math mne discussion se dekh liya
        
        int mod = 1000000007;
        long int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            nums[i] += nums[i-1];
        }
        
        for(int i = 0; i < n; ++i){
            int j = lower_bound(begin(nums)+i+1, begin(nums)+n-1, 2*nums[i]) - begin(nums);
            int k = upper_bound(begin(nums)+i+1, begin(nums)+n-1, (nums[i] + nums[n-1])/2) - begin(nums) - 1;
            ans=(ans%mod+max(0,k-j+1))%mod;
            ans %= mod;
        }
        
        return ans%mod;
    }
};