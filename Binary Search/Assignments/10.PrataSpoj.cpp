// https://www.spoj.com/problems/PRATA/

// https://www.spoj.com/problems/PRATA/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &cookRanks, int np, int time) {
    int currP = 0;
    for (int i = 0; i < cookRanks.size(); i++) {
        int R = cookRanks[i], j = 1;
        int timeTaken = 0;
        while (true) {
            if (timeTaken + (R * j) <= time) {
                ++currP;
                timeTaken += (R * j);
                ++j;
            } else {
                break;
            }
        }
        if (currP >= np) {
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(int np, vector<int> cookRanks) {
    int start = 0;
    int highestRank = *max_element(cookRanks.begin(), cookRanks.end());
    int end = highestRank * (np * (np + 1)) / 2;
    int ans = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(cookRanks, np, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int np, nc;
        cin >> np >> nc;
        vector<int> cookRanks;
        while (nc--) {
            int r;
            cin >> r;
            cookRanks.push_back(r);
        }
        cout << minTimeToCompleteOrder(np, cookRanks) << endl;
    }
    return 0;
}
