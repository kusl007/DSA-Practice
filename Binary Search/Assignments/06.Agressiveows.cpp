// coding ninjas => Aggressive Cows
//https://www.naukri.com/code360/problems/aggressive-cows_1082559
//maximum possible minimum distance =>this statement is used to know about binary search


  bool isPossible(const std::vector<int> &stalls, int k, int mid) {
        int cowCount = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= mid) {
                cowCount++;
                if (cowCount == k) {
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int s = 1;
        int maxi = stalls[stalls.size() - 1];
        int e = maxi;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(stalls, k, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }

