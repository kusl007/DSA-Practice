
//gfg The Painter's Partition Problem-II
// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
class Solution
{
  public:
  bool ifPossible(int arr[], int n, int k,int mid){
      int count =1;
      int sum=0;
     for(int i=0;i<n;i++){
         if (arr[i]>mid){
             return false;
         }
         if(sum+arr[i]<=mid){
             sum+=arr[i];
         }
         else{
             count++;
             if(count>k){
                 return false;
             }
             sum=arr[i];
         }
         
     }
     return true;
  }
    
    long long minTime(int arr[], int n, int k)
    {
    
    long long s=0;
    long long ans =-1;
    long long sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        
    }
    long long e=sum;
    while(s<=e){
        int mid =s+(e-s)/2;
        if(ifPossible(arr,n,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else
        s=mid+1;
    }
    return ans;
    }
};