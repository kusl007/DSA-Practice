#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> v) {
    int row = v.size();
    int col = v[0].size();
    for (int i = 0; i < row; i++) {
        // even => top to bottom
        // odd => bottom to top
        if ((i & 1) == 0) {
            for (int j = 0; j < col; j++) {
                cout << v[j][i] << " ";
            }
        } else {
            for (int j = col - 1; j >= 0; j--) {
                cout << v[j][i] << " ";
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    wavePrint(matrix);

    return 0;
}
