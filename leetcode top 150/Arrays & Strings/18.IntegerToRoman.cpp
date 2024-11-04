//12. Integer to Roman
https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    string chars(int i) {
        if (i == 3000) return "MMM";
        if (i == 2000) return "MM";
        if (i == 1000) return "M";
        if (i == 900) return "CM";
        if (i == 800) return "DCCC";
        if (i == 700) return "DCC";
        if (i == 600) return "DC";
        if (i == 500) return "D";
        if (i == 400) return "CD";
        if (i == 300) return "CCC";
        if (i == 200) return "CC";
        if (i == 100) return "C";
        if (i == 90) return "XC";
        if (i == 80) return "LXXX";
        if (i == 70) return "LXX";
        if (i == 60) return "LX";
        if (i == 50) return "L";
        if (i == 40) return "XL";
        if (i == 30) return "XXX";
        if (i == 20) return "XX";
        if (i == 10) return "X";
        if (i == 9) return "IX";
        if (i == 8) return "VIII";
        if (i == 7) return "VII";
        if (i == 6) return "VI";
        if (i == 5) return "V";
        if (i == 4) return "IV";
        if (i == 3) return "III";
        if (i == 2) return "II";
        if (i == 1) return "I";
        return "";
    }
    
    string intToRoman(int num) {
        string ans = "";

        // Thousands place
        int thousands = (num / 1000) * 1000;
        ans += chars(thousands);
        num %= 1000;

        // Hundreds place
        int hundreds = (num / 100) * 100;
        ans += chars(hundreds);
        num %= 100;

        // Tens place
        int tens = (num / 10) * 10;
        ans += chars(tens);
        num %= 10;

        // Ones place
        ans += chars(num);
        
        return ans;
    }
};
