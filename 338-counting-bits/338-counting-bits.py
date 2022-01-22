class Solution:
    def countBits(self, n: int) -> List[int]:
        '''
        ans[0] = 0
        ans[1] = 1
        ans[2] = ans[2/2] = 1
        ans[3] = ans[3/2]+1 = 2
        
        '''
        ans = [0]*(n+1)
        for i in range(1,n+1):
            ans[i] = ans[i>>1] + (i&1)
        return ans