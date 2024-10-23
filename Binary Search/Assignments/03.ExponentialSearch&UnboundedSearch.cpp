//exponential search ,doubling search ,etc


//appplication
//very very large array 

//step

// if(a[0]==x){
//     return 0;
// }
// int i=1;
// while(i<n && a[i]<=x){
//     i=i*2;
// }
// return bs(a,i/2,min(i,n-1),x);


#include <iostream>
using namespace std;

int bs(int a[],int s,int e,int x){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
    
}
int exponentialSearch(int a[],int n,int x){
    if(a[0]==x)return 0;
    int i=1;
    while(i<n && a[i]<=x){
        i=i*2; //i<<1
    }
    return bs(a,i/2,min(i,n-1),x);
}

int main(){
    int a[]={3,4,5,6,11,13,14,15,56,70};
    int n=sizeof(a)/sizeof(int);
    int x=13;
    int ans=exponentialSearch(a,n,x);
    cout<<ans<<endl;
    return 0;
}


//better than binary seach in huge array
//if target is at beginning
//unbounded array =>no end