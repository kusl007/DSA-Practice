
#include <iostream>
using namespace std;


int position(string str, int n,int i,int target,int &ans){
    if(i>=n){
        cout<<"target not found"<<endl;
        return ans;
    }
    
    if (str[i]==target){
        ans=i;
    }
    return position(str,n,i+1,target,ans);
}
int main() {
    
string str="abcdddefdg";
int length =str.length();
int i=0;
int FinalAns=-1;
char target='d';
int ans =position(str,length,i,target,FinalAns);
if(ans>=0){
cout<<"the character is in "<< ans<< " position"<<endl;
}



    return 0;
}