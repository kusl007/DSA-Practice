//last occurence of a string

// string ="abcdbgcgd"
//          012345678
// char = "d"
//output=8;



//methods iteratively and then recursively
// search from right to left
//search from left to right

//method 1: Left to right

//base case
// 

//solution
//  if (str[i]==ch){
// ans =i;}




#include <iostream>
using namespace std;


int position(string str, int n,int i,int target){
    if(i<0){
        cout<<"target not found"<<endl;
        return -1;
    }
    if (str[i]==target){
        return i;
    }
    return position(str,n,i-1,target);
}
int main() {
    
string str="abcdddefg";
int length =str.length();
int i=length-1;
char target='z';
int ans =position(str,length,i,target);
if(ans>=0){
cout<<"the character is in "<< ans<< " position"<<endl;
}



    return 0;
}


