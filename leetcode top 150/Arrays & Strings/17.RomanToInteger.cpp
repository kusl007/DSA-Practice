// 13. Roman to Integer
//https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
int nums(char ch){
    if(ch=='I'){
        return 1;
    }
    else if(ch=='V'){
        return 5;
    }
    else if(ch=='X'){
        return 10;
    }
    else if(ch=='L'){
        return 50;
    }
    else if(ch=='C'){
        return 100;
    }
     else if(ch=='D'){
        return 500;
    }
    else if(ch =='M'){
        return 1000;
    }
    return -1;
}
    int romanToInt(string s) {
        int n=s.length();
        int sum =0;
        int i=0;
        while(i<n-1){
            if (nums(s[i])<nums(s[i+1])){
                sum-=nums(s[i]);
            }
            else{
                sum+=nums(s[i]);
            }
            i++;
        }
        sum+=nums(s[n-1]);
        return sum;
        
    }
};