
#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int& size,int i){
    if(i==size-1){
        return true;
    }
    if(arr[i+1]<arr[i]){
        return false;
    }
    
    return checkSorted(arr,size,i+1);
  
}

int main() {
   vector <int> v{1,2,3,4,5,6,1};
    int size=v.size();
    int i=0;
   bool ans= checkSorted(v,size,i);
   cout<<ans<<endl;
   if(ans){
       cout<<"The array is sorted";
   }
   else{
       cout<<"The array is not sorted";
   }
   

    return 0;
}