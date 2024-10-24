//https://www.spoj.com/problems/EKO/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int> &trees, long long int m, long long int height) {
    long long int woodCollected = 0;
    for (int i = 0; i < trees.size(); i++) {
        if (trees[i] > height) {
            woodCollected += trees[i] - height;
        }
    }
    return woodCollected >= m;
}

int maxSawBladeHeight(vector<long long int> &trees, long long int m) {
    long long int start = 0;
    long long int end = *max_element(trees.begin(), trees.end());
    long long int ans = -1;

    while (start <= end) {
        long long int mid = (start + end) / 2;
        if (isPossibleSolution(trees, m, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    long long int n, m;
    cout<<"Enter the size of Array and minimum length of wood you required"<<endl;
    cin >> n >> m;
    vector<long long int> trees;
    for (long long int i = 0; i < n; i++) {
        long long int height;
        cout<<"Enter the height of "<<i+1<<"th tree"<<endl;
        cin >> height;
        trees.push_back(height);
    }
    cout <<"You Must Cut the tree at minimum height => "<< maxSawBladeHeight(trees, m) << " m"<< endl;

    return 0;
}
