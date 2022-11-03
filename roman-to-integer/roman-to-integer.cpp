class Solution {
public:
    /*
    *   I, V, X, L, C, D, M
    *   IV, IX, XL, XC, CD, CM
    */
    int romanToInt(string s) {
        int x = 0, i;
        int n = s.size();
        for(i = 0; i < n;) {
            switch(s[i]) {
                case 'I': {
                    deduceI(i, s, x);
                    break;
                }
                case 'V': {
                    deduceV(i, s, x);
                    break;
                }
                case 'X': {
                    deduceX(i, s, x);
                    break;
                }
                case 'L': {
                    deduceL(i, s, x);
                    break;
                }
                case 'C': {
                    deduceC(i, s, x);
                    break;
                }
                case 'D': {
                    deduceD(i, s, x);
                    break;
                }
                case 'M': {
                    deduceM(i, s, x);
                    break;
                }
            }
        }
        return x;
    }
    
    void deduceI(int& i, string& s, int& x) {
        int n = s.size();
        if(i+1 != n) {
            if(s[i+1] == 'V'){
                x += 4;
                i += 2;
                return;
            }
            else if(s[i+1] == 'X') {
                x += 9;
                i += 2;
                return;
            }
            else {
                x += 1;
                i += 1;
                return;
            }
        }
        else {
            x += 1;
            i += 1;
            return;
        }
        return;
    }
    
    void deduceV(int& i, string& s, int& x) {
        int n = s.size();
        x += 5;
        i += 1;
        return;
    }
    
    void deduceX(int& i, string& s, int& x) {
        int n = s.size();
        if(i+1 != n) {
            if(s[i+1] == 'L'){
                x += 40;
                i+=2;
                return;
            }
            else if(s[i+1] == 'C') {
                x += 90;
                i += 2;
                return;
            }
            else {
                x += 10;
                i += 1;
                return;
            }
        }
        else {
            x += 10;
            i += 1;
            return;
        }
        return;
    }
    
    void deduceL(int& i, string& s, int& x) {
        int n = s.size();
        x += 50;
        i += 1;
        return;
    }
    
    void deduceC(int& i, string& s, int& x) {
        int n = s.size();
        if(i+1 != n) {
            if(s[i+1] == 'D'){
                x += 400;
                i+=2;
                return;
            }
            else if(s[i+1] == 'M') {
                x += 900;
                i += 2;
                return;
            }
            else {
                x += 100;
                i += 1;
                return;
            }
        }
        else {
            x += 100;
            i += 1;
            return;
        }
        return;
    }
    
    void deduceD(int& i, string& s, int& x) {
        int n = s.size();
        x += 500;
        i += 1;
        return;
    }
    
    void deduceM(int& i, string& s, int& x) {
        int n = s.size();
        x += 1000;
        i += 1;
        return;
    }
};