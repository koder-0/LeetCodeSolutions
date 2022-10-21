class Solution {
public:
    /*
    *   Input: nums: vector<int>, target: int
    *   range of nums: -10^9 to 10^9
    *   length of nums: 10^4
    *   range of target: -10^9 to 10^9
    *   brute force : for each num in nums, check if there is a num in nums that sum up to target
    *   time complexity: O(n^2)
    *   we can use a map to store a key value pair where key is the difference of a num and target
    *   which is to be used to find the required num in nums. the value will be the corresponding
    *   index of the num.
    *   time complexity: O(n). while populating the map. if we find the right candidate. we return the answer.
    *   so we traverse the vector just once and we do 2 operation insert and find in unordered_map.
    *   space: O(n);
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> diffMap;
        for(int i = 0; i < size; ++i) {
            auto itr = diffMap.find(nums[i]);
            if(itr != diffMap.end()) {
                return {i, itr->second};
            }
            else {
                //target-nums[i]
                // if(target < 0 && nums[i] > 0) {
                //     if(nums[i] + INT_MIN > (target)) continue;
                // }
                // else if(target > 0 && nums[i] < 0) {
                //     if(INT_MAX - abs(nums[i]) < target) continue;
                // }
                diffMap[target-nums[i]] = i;
            }
        }
        return {};
    }
};