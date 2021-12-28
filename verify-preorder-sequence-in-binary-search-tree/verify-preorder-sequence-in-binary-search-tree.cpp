class Solution {
public:
    bool Util(vector<int>& arr, int l, int r, int mn, int mx){
        if(l > r) return mn <= mx;
        if(l == r) return arr[l] >= mn && arr[l] <= mx;
        int val = arr[l];
        int idx = r+1;
        for(int i = l; i <= r; ++i){
            if(arr[i] > val){
                idx = i;
                break;
            }
        }
        
        bool left = Util(arr, l+1, idx-1, mn, val);
        bool right = Util(arr, idx, r, val, mx);
        
        return left&&right;
    }
    bool verifyPreorder(vector<int>& preorder) {
        //if it is preorder, we can test by simply applying binary search
        //but if it is not, then what to do
        //one is linearly traverse to find the first greatest number in the arr then verify 
        // the left and right subarray of that number, right starts from that number
        // it is n log n approach as in worst case we may need to traverse the whole array
        // and each time we apply the verification on parts of the array
        //let's implement it then
        
        int n = preorder.size();
        if(n == 0 || n == 1) return true;
        int val = preorder[0];
        int idx = n;
        for(int i = 1; i < n; ++i){
            if(preorder[i] > val) {
                idx = i;
                break;
            }
        }
        bool left = Util(preorder, 1, idx-1, INT_MIN, val);
        bool right = Util(preorder, idx, n-1, val, INT_MAX);
        return left&&right;
    }
};