class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        //O(orders)log(sum(all elements in inventory));
        //O(10^9)log(10^18)
        //not feasible
        //put elements in map(ordered)
        //start from end of map
        //take for difference between current element and element just after
        //add sum of numbers from (element just after) to (current element);
        //add it to result, 
        //key and cnt
        //total number you can add is diff*cnt
        //so check if diff*cnt > orders
        //if yes, add them up
        //else, add till orders/cnt and orders%cnt with a number left
        //
        
        
        //cnt*diff >= orders
        //orders/cnt
        //key = 6, diff = 3
        //key-diff = 3 = x
        //(key*(key+1))/2 - (x*(x+1))/2;
        //21-6 = 15
        //key*key + key - ((key-diff)*(key-diff+1))
        //key*key + key - (key*key - key*diff + key - diff*key + diff*diff - diff)
        //key*diff+key*diff - diff*diff + diff;
        //6*3*2-3*3+3 = 36-9+3
        
//         priority_queue<int> Values;
//         for(auto quant: inventory)Values.push(quant);
//         long long int res = 0;
//         int mod = 1e9+7;
//         while(orders--){
//             int val = Values.top();
//             Values.pop();
//             res += val%mod;
//             res %= mod;
//             Values.push(val-1);
//         }
        
//         return res;
        
        map<int, int> mp;
        int mod = 1e9+7;
        for(auto x: inventory){
            mp[x]++;
        }
        
        long long res = 0;
        for(auto it = mp.rbegin(); it != mp.rend(); ){
            long long  key = it->first, cnt = it->second, diff = 0;
            it++;
            if(it == mp.rend()){
                diff = key;
            }
            else diff = key-it->first;
            if(cnt*diff >= orders){
                diff = orders/cnt;
                res += (1ll*cnt*(1ll*key*diff+1ll*key*diff - 1ll*diff*diff + 1ll*diff))/2;
                res %= mod;
                int rem = orders%cnt;
                res += rem*(key-diff);
                res %= mod;
                break;
            }
            else{
                res += (cnt*(key*diff+key*diff - diff*diff + diff))/2;
                res %= mod;
                mp.erase(key);
                mp[key-diff] += cnt;
                orders -= cnt*diff;
            }
        }
        
        return res%mod;
    }
};