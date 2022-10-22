class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int st = 0, en = 0, size = s.size();
        int freq[256] = {0};
        while(en < size) {
            freq[s[en]]++;
            while(st < en && freq[s[en]] > 1) {
                freq[s[st++]]--;
            }
            res = max(res, en-st+1);
            cout<<st<<" "<<en<<" "<<res<<endl;
            en++;
        }
        // while(st < en && freq[s[st]] > 1) {
        //     freq[s[st++]]--;
        // }
        // res = max(res, en-st+1);
        return res;
        
    }
};