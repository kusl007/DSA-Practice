// leetcode 135. Candy
// https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;

        int sum = 1, i = 1;

        while (i < n) {
            //flat surface
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            //increasing surface
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }

            int down = 0;
            //decreasing surface
            while (i < n && ratings[i] < ratings[i - 1]) {
                down += 1;
                sum += down;
                i++;
            }

            if (down >= peak) {
                sum += down - peak + 1;
            }
        }

        return sum;
    }
};
