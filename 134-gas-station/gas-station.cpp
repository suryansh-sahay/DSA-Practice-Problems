class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int check=0;
        for(int i=0; i<gas.size(); i++) check+=gas[i]-cost[i];
        if(check<0) return -1;

        int start=0, gass=0;
        for(int i=0; i<gas.size()-1; i++){
            gass+=gas[i]-cost[i];
            if(gass<0) gass=0, start=i+1;
        }
        return start;
    }
};