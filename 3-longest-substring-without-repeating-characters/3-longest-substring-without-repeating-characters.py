class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = {}
        tmp = ans = 0
        i = j = 0
        while i < len(s):
            if s[i] not in count or count[s[i]] == 0:
                if s[i] not in count: count[s[i]] = 1
                else: count[s[i]] += 1
                i+=1
                ans = max(ans, i-j)
            else:
                while j < i and count[s[i]] != 0:
                    count[s[j]]-=1
                    j+=1
        return ans
                
            