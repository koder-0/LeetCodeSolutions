class Solution {
public:
    int myAtoi(string s) {
        int res = 0, val = 0;
        bool isNumRead = false;
        bool isNumNegative = false;
        for(auto c: s) {
            if(isdigit(c)) {
                isNumRead = true;
                val = c-'0';
                //2147483647  2147483646  2147483648
                //-2147483648  -2147483647  -2147483649
                if(isNumNegative) {
                    if(res > (abs)(INT_MIN/10)) {
                        // cout<<"i am here neg. "<<res<<" "<<val<<endl;
                        return INT_MIN;
                    }
                    if(res == (abs)(INT_MIN/10) && val >= 8) return INT_MIN;
                }
                else {
                    // cout<<res<<" "<<(INT_MAX/10)<<endl;
                    if(res > (INT_MAX/10)) {
                        // cout<<"i am here. "<<res<<" "<<val<<endl;
                        return INT_MAX;
                    }
                    if(res == (INT_MAX/10) && val >= 7) {
                        // cout<<"i should be here.";
                        return INT_MAX;
                    }
                }
                res = res*10 + val;
            }
            else if(c == '+'){
                if(isNumRead) break;
                isNumRead = true;
                isNumNegative = false;
                continue;
            }
            else if(c == '-') {
                if(isNumRead) break;
                isNumRead = true;
                isNumNegative = true;
                continue;
            }
            else if(c == ' ') {
                if(isNumRead) break;
                continue;
            }
            else break;
        }
        // cout<<res<<endl;
        return isNumNegative ? -res : res;
    }
};