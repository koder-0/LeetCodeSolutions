class Solution {
public:
    /*
    *   I, V, X, L, C, D, M
    *   if num >= 1k: deduceM(int, roman);
    *   if num >= 500: deduceD(int, roman);
    *   if num >= 100: deduceC(int, roman);
    *   if num >= 50: deduceL(int, roman);
    *   if num >= 10: deduceX(int, roman);
    *   if num >= 5: deduceV(int, roman);
    *   if num >= 1: deduceI(int, roman);
    *   return roman;
    */
    string intToRoman(int num) {
        int x = num;
        string roman = "";
        if(x >= 1000) {
            deduceM(x, roman);
        }
        if(x >= 500) {
            deduceD(x, roman);
        }
        if(x >= 100) {
            deduceC(x, roman);
        }
        if(x >= 50) {
            deduceL(x, roman);
        }
        if(x >= 10) {
            deduceX(x, roman);
        }if(x >= 5) {
            deduceV(x, roman);
        }
        if(x >= 1) {
            deduceI(x, roman);
        }
        return roman;
    }
    
    void deduceM(int& num, string& roman) {
        if(num < 1000) return;
        int n = num/1000;
        while(n--) roman += "M";
        num %= 1000;
        return;
    }
    void deduceD(int& num, string& roman) {
        if(num < 500) return;
        if(num >= 900) {
            roman += "CM";
            num %= 900;
            return;
        }
        int n = num/500;
        while(n--) roman += "D";
        num %= 500;
        return;
    }
    void deduceC(int& num, string& roman) {
        if(num < 100) return;
        if(num >= 400) {
            roman += "CD";
            num %= 400;
            return;
        }
        int n = num/100;
        while(n--) roman += "C";
        num %= 100;
        return;
    }
    void deduceL(int& num, string& roman) {
        if(num < 50) return;
        if(num >= 90) {
            roman += "XC";
            num %= 90;
            return;
        }
        int n = num/50;
        while(n--) roman += "L";
        num %= 50;
        return;
    }
    void deduceX(int& num, string& roman) {
        if(num < 10) return;
        if(num >= 40) {
            roman += "XL";
            num %= 40;
            return;
        }
        int n = num/10;
        while(n--) roman += "X";
        num %= 10;
        return;
    }
    void deduceV(int& num, string& roman) {
        if(num < 5) return;
        if(num >= 9) {
            roman += "IX";
            num %= 9;
            return;
        }
        int n = num/5;
        while(n--) roman += "V";
        num %= 5;
        return;
    }
    void deduceI(int& num, string& roman) {
        if(num < 1) return;
        if(num >= 4) {
            roman += "IV";
            num %= 4;
            return;
        }
        int n = num/1;
        while(n--) roman += "I";
        num %= 1;
        return;
    }
};