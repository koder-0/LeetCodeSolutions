class Solution {
public:
    
    bool canDistribute(int n, vector<int>& quantities, int maxAmount){
        //[15, 10, 10]
        //6
        //ans: 8
        
        int i = 0;
        while(i < quantities.size()){
            int stores = (quantities[i]-1)/maxAmount+1;
            n -= stores;
            if(n < 0) return false;
            i++;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int high = *max_element(begin(quantities), end(quantities));
        int low = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canDistribute(n, quantities, mid))high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};