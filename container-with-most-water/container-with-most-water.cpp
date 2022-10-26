class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int st = 0, en = size-1;
        int res = 0;
        while(st <= en) {
            res = max(res, (en-st)*(min(height[st], height[en])));
            if(height[st] < height[en]) st++;
            else en--;
        }
        return res;
    }
};