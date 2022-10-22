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
                        return INT_MIN;
                    }
                    if(res == (abs)(INT_MIN/10) && val >= 8) return INT_MIN;
                }
                else {
                    if(res > (INT_MAX/10)) {
                        return INT_MAX;
                    }
                    if(res == (INT_MAX/10) && val >= 7) {
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
        return isNumNegative ? -res : res;
    }
};