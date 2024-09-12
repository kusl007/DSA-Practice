
#include <iostream>
using namespace std;


void PrintReverseCounting(int n){
    if (n==0){
        
    
        return ;
    }
cout<<n << " ";
PrintReverseCounting(n-1);
    
}
void PrintCounting(int n){
    if (n==0){
        return ;
    }
PrintCounting(n-1);
cout<<n << " ";
    
}
int main() {
    int n;
 cout<<"enter the number"<<endl;
 cin>>n;
 cout<<"The counting is"<<endl;
PrintCounting(n);
cout<<endl;
 cout<<"The reverse counting is"<<endl;
PrintReverseCounting(n);
 
   

    return 0;
}