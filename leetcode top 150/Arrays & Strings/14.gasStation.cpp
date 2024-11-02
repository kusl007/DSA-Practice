//leetcode 134. Gas Station
//https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalDiff=0,n=gas.size(),fuel=0,index=0;
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            totalDiff+=diff;
            fuel+=diff;
            if(fuel<0){
                index=i+1;
                fuel=0;
            }

        }

        if(totalDiff<0){
            return -1;
        }
        return index;
    }
};