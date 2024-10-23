//https://www.naukri.com/code360/problems/allocate-books_1090540
//maximum number of pages assigned to student is minimum=>this statement is used to know about binary search 


bool isPossbile(vector<int> &arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
   
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
     if (m > n) return -1;
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;  
    int mid = s + (e - s) / 2;
    
    while (s <= e) {
        if (isPossbile(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
