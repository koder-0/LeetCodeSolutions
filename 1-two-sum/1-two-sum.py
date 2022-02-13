class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            n = target-nums[i]
            if n in hashmap:
                return [i, hashmap[n]]
            hashmap[nums[i]] = i